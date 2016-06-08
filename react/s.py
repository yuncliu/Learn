#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
from flask import Flask, render_template, abort, make_response

app = Flask(__name__)

mime_type={'.html': 'text/html',
    '.css': 'text/css',
    '.js': 'application/x-javascript',
    '.py': 'text/plain',
    '.json': 'application/json'}

@app.route('/api/<api>')
def api(api):
    return "Hellow"

@app.route('/', defaults={'path': '.'})
@app.route('/<path:path>')
def root(path):
    print('[{0}]'.format(path))
    print(os.getcwd())
    if os.path.isdir(path):
        data = [os.path.join(path, entry.name) for entry in os.scandir(path)]
        for i in data:
            print(i)
        return render_template('index.html', data=data)

    if os.path.isfile(path):
        ext_name = os.path.splitext(path)[1]# == '.css':
        with open(path) as f:
            resp = make_response(f.read())
            try:
                resp.headers['content-type'] = mime_type[ext_name]
            except KeyError:
                resp.headers['content-type'] = 'text/plain'
            return resp

    abort(404)

if __name__=="__main__":
    app.run(host='0.0.0.0', port=8080, debug=True)
