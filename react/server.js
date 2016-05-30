let http = require("http");
let url = require("url");
let fs = require("fs");
let path=require('path');

function handleDirectory(p, response) {
    response.writeHead(200, {"Content-Type": "text/html"});
    response.write("directory");
    response.end();
}

function onRequest(request, response) {
    let pathname = url.parse(request.url).pathname;
    //console.log(path)
    let p = path.join(__dirname, pathname);
    console.log(p);
    fs.stat(p, (err, stats)=>{
        console.log("process [%s]", p);
        if (err) {
            console.log('%s not exist', p);
            response.writeHead(404, {"Content-Type": "text/html"});
            response.end();
        } else {
            if(stats.isFile()) {
                console.log('%s is a file', p);
                //ex = path.extname(p)
                fs.readFile(p, {flag:"r", encoding:"utf8"}, (err, data)=>{
                    response.writeHead(200, {"Content-Type": "text/html"});
                    response.write(data);
                    response.end();
                });
            }
            if (stats.isDirectory()) {
                console.log('%s is a directory', p);
                handleDirectory(p, response)
            }
        }
    });
}

http.createServer(onRequest).listen(8888);
