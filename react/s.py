#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
import json
from flask import Flask, render_template, abort, make_response, request
from mimetypes import MimeTypes

app = Flask(__name__)

m = MimeTypes()
comment = ['aaa', 'bbb', 'ccc']

@app.route('/api/<api>', methods=['GET', 'POST'])
def api(api):
    if api == '1':
        resp = make_response(json.dumps({1:1}))
        resp.headers['content-type'] = 'application/json'
        return resp
    if api == 'print':
        resp = make_response()
        resp.headers['content-type'] = 'application/json'
        resp.set_data(json.dumps({'result' : 'done'}))
        return resp

    if api == 'list':
        resp = make_response()
        resp.headers['content-type'] = 'application/json'
        resp.set_data(json.dumps(comment))
        return resp

    if api == 'submit_comment':
        resp = make_response()
        resp.headers['content-type'] = 'application/json'
        print('get a submit')
        print(request.get_json(silent = True))
        tmp = request.get_json(silent = True)
        try:
            comment.append(tmp['key'])
        except Exception as e:
            pass

        resp.set_data(json.dumps(comment))
        return resp

    return "Hellow"

@app.route('/', defaults={'path': '.'})
@app.route('/<path:path>')
def root(path):
    print('[{0}]'.format(path))
    print(os.getcwd())
    if os.path.isdir(path):
        data = dict(zip([entry.name for entry in os.scandir(path)],
            [os.path.join(path, entry.name) for entry in os.scandir(path)]))
        for k, v in data.items():
            print('[{0}][{1}]'.format(k, v))
        return render_template('index.html', data=data)

    if os.path.isfile(path):
        with open(path) as f:
            resp = make_response(f.read())
            resp.headers['content-type'] = m.guess_type(path)[0]
            return resp

    abort(404)

if __name__=="__main__":
    app.run(host='0.0.0.0', port=8080, debug=True)
