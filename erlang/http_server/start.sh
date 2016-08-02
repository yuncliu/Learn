#!/bin/bash
rm *.beam
erlc mylib.erl
./http_server.erl
