let http = require("http");
let url = require("url");
let fs = require("fs");
let path=require("path");

function handleDirectory(p, response) {
    fs.readdir(p,{flag : "r", encoding:"utf8"}, (err, files)=>{
        if (err) {
            response.writeHead(404, {"Content-Type": "text/html"});
            response.end();
        } else {
            response.writeHead(200, {"Content-Type": "text/html"});
            response.write("<ul>");
            for (let file of files) {
                let s = "<li><a href=" +file + ">" + file + "</a></li>"
                response.write(s);
            }
            response.write("</ul>");
            response.end();
        }
    });
}

const handleAPI = (request, response) => {
    let parsedurl = url.parse(request.url);
    response.writeHead(200, {"Content-Type": "text/html"});
    //response.write("{ 'name': 'xxx' }")
    let v = "value";
    let data = {key:v}
    console.log(data)
    response.write(JSON.stringify(data))
    response.end();
}

function onRequest(request, response) {
    let pathname = url.parse(request.url).pathname;
    console.log(url.parse(request.url))
    let p = path.join(__dirname, pathname);
    fs.stat(p, (err, stats)=>{
        console.log("process [%s]", p);
        if (err) {
            if (pathname == "/api") {
                handleAPI(request, response)
            } else {
                console.log("%s not exist", p);
                response.writeHead(404, {"Content-Type": "text/html"});
                response.write("404")
                response.end();
            }
        } else {
            if(stats.isFile()) {
                console.log("%s is a file", p);
                ex = path.extname(p)
                fs.readFile(p, {flag:"r", encoding:"utf8"}, (err, data)=>{
                    if (ex==".html") {
                        response.writeHead(200, {"Content-Type": "text/html"});
                    } else {
                        response.writeHead(200, {"Content-Type": "text/plain"});
                    }
                    response.write(data);
                    response.end();
                });
            }
            if (stats.isDirectory()) {
                console.log("%s is a directory", p);
                handleDirectory(p, response)
            }
        }
    });
}

http.createServer(onRequest).listen(8888);
