#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import socket
import os
import sys
import http.client
import argparse
import ssl

class Request(object):
    def __init__(self):
        self.use_https = False
        self._text = None
        self.req = None
        self.host = None
        self.port = None
        self.sni = None

    def set_addr(self, addr):
        self.host, self.port = addr.split(':')
        if self.port.isnumeric():
            self.port = int(self.port)
        else:
            print('port is not number')
            raise Exception('Port should be a number')

    def get_addr(self):
        return self.host, self.port

    def get_text():
        return self._text

    def set_text(self, t):
        self._text = t
        self.req = self._text.replace(os.linesep, '')
        self.req = self.req.replace('\\r', '\r')
        self.req = self.req.replace('\\n', '\n')

    def send(self):
        if self.use_https:
            context = ssl.SSLContext(ssl.PROTOCOL_SSLv23)
            if self.sni is None:
                s = context.wrap_socket(socket.socket(socket.AF_INET), server_hostname=self.host)
            else:
                s = context.wrap_socket(socket.socket(socket.AF_INET), server_hostname=self.sni)
        else:
            s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        # now connect to the web server on port 80 - the normal http port
        try:
            s.connect((self.host, self.port))
            s.send(self.req.encode())
            response = http.client.HTTPResponse(s)
            response.begin()
            return response
        except ssl.SSLError as e:
            print("Can't establsh ssl connection")
            return None
        except Exception as e:
            raise e

    addr = property(get_addr, set_addr)
    text = property(get_text, set_text)

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--addr', default='localhost:90', help="set address --addr=localhost:80")
    parser.add_argument('--https', action='store_true', default = False, help="if use https")
    parser.add_argument('--sni', help="set Server Name Indication")
    parser.add_argument('--file', help="set file to send")
    args = parser.parse_args()

    if len(sys.argv) == 1:
        #parser.print_help()
        parser.print_usage()
        return

    x = Request()

    if args.addr:
        x.addr = args.addr
    else:
        x.addr = 'localhost:80'

    if args.https:
        print('https enabled')
        x.use_https = True
        x.port = 443
    else:
        print('https not enabled')

    if args.file:
        x.text = open(args.file, 'r').read()
    else:
        x.text = 'GET / HTTP/1.1\\r\\n\\r\\n'

    resp  = x.send()
    if resp is None:
        print('no response')
        return
    print('Response [{0}]:'.format(resp.code))
    for i in resp.getheaders():
        print(i)

if __name__ == "__main__":
    main()
