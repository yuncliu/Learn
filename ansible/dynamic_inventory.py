#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import argparse
import json

"""
ansible -i dynamic_inventory.py all --list-host
ansible -i dynamic_inventory.py test --list-host
"""
if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    group = parser.add_mutually_exclusive_group()
    group.add_argument('--host', help = "called by ansible")
    group.add_argument('--list', action = 'store_true', default = False,
            help = "called by ansible")
    arg = parser.parse_args()

    json_str = """{
    "all" : {
        "hosts" : [ "june", "july" ],
        "vars" : { "a" : "123" },
        "children" : [ "test" ]
    },
    "test" : {
        "hosts" : [ "host1", "host2" ],
        "vars" : { "b" : "123" }
    },
    "_meta": {
        "hostvars": {
            "july": {"ansible_ssh_user" : "yuncliu",  "ansible_ssh_pass" : "yuncliu"},
            "june": {"ansible_ssh_user" : "yuncliu",  "ansible_ssh_pass" : "yuncliu"}
        }
    }
    }"""
    json_obj = json.loads(json_str);

    if arg.host:
        try:
            print(json.dumps(json_obj['meta']['hostvars'][arg.host]))
        except:
            print(json.dumps({}))

    if arg.list:
        print(json.dumps(json_obj))
