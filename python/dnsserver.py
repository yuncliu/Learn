#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from dnslib.server import DNSServer
from dnslib.server import BaseResolver
from dnslib.server import DNSLogger
from dnslib.server import DNSRecord
from dnslib import RR
import time
import sqlite3

class Data(object):
    """
    use a sqlite3 table Host
    |ip         |host           |
    |1.1.1.1    |www.xxx.com    |
    |2.2.2.2    |www.yyy.com    |
    """
    def __init__(self):
        self.db = sqlite3.connect("dns.db")
        self.create_table()

    def create_table(self):
        if not self.check_if_table_exist('Host'):
            c = self.db.cursor()
            c.execute("CREATE TABLE Host (ip TEXT, hostname TEXT, PRIMARY KEY(ip))")

    def check_if_table_exist(self, table_name):
        c = self.db.cursor()
        t = c.execute("SELECT name FROM sqlite_master WHERE type='table' AND name='{0}';".format(table_name))
        for i in t:
            return True
        return False

    def insert(self, ip, host):
        try:
            c = self.db.cursor()
            c.execute("INSERT INTO Host Values ('{0}', '{1}')".format(ip, host))
            self.db.commit()
        except sqlite3.IntegrityError:
            return False

        return True

    def get_ip_by_host(self, host):
        c = self.db.cursor()
        r = c.execute("SELECT ip From Host WHERE hostname='{0}'".format(host))
        return [i[0] for i in r]

class TestResolver:
    def __init__(self):
        pass

    def resolve(self, request, handler):
        db = Data()
        reply = request.reply()
        print(type(request))
        print('------------')
        #print(request.q)
        host = None
        ip = None
        for i in request.questions:
            host = i.qname
            ip = db.get_ip_by_host(host)
            print("Host {0} got ip {1}".format(host, ip))
            break

        print('------------')
        reply.add_answer(*RR.fromZone("{0} 60 A {1}".format(host, ip[0])))
        return reply

if __name__ == "__main__":
    resolver = TestResolver()
    logger = DNSLogger(prefix=False)
    server = DNSServer(resolver,port=53,address="localhost",logger=logger)
    server.start_thread()

    while True:
        time.sleep(10)
