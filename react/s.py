from flask import Flask
import os

app = Flask(__name__, static_url_path='', static_folder='')


def serve_dir(path):
    h = "<html>\n"
    h = h + "<ul>\n"
    for entry in os.scandir(path):
        a = "<li><a href='{0}/{1}'>{1}</a></li>\n".format(path, entry.name)
        h = h + a

    h = h + "</ul>\n"
    h = h + "</html>"
    return h

@app.route('/')
def root():
    print('request path is /')
    return serve_dir('.')

@app.route('/api/<path>')
def path(path):
    print(path)
    return "api"

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=3000)
