#!/usr/bin/env python3
import json

class Node:
    def __init__(self):
        self.key = None         #used to store attribute name
        self.val = None         #used to store result of target attribute
        self.parent_attr = None #belongs to which class classified by parent node's attribute
        self.entropy = 0
        self.children = list()

    def __str__(self):
        """make a json string, so that it could be save to file"""
        s = '{' + """"key" : "{0}",
"parent_attr":"{3}",
"value" : "{1}",
"entropy":"{2}",
"children" : [ """.format(self.key, self.val, self.entropy, self.parent_attr)
        sc = list()
        for i in self.children:
            sc.append(i.__str__())

        s = s + ','.join(sc)
        s = s + " ]}"
        return s

    def add_child(self, child):
        if type(child) == type(self):
            self.children.append(child)

    def load_from_json(self, j):
        """recover from a json object"""
        self.key = j['key']
        self.val = j['value']
        self.entropy = j['entropy']
        for i in j['children']:
            t = Node()
            t.load_from_json(i)
            self.children.append(t)

    def get_children(self):
        return self.children

    def get_children_by_attr(self, attr):
        for i in self.children:
            if i.parent_attr == attr:
                return i
        return None

class Tree:
    def __init__(self):
        self.root = Node()

    def save_to_file(self, file_name):
        f = open(file_name, 'w')
        f.write(self.root.__str__())
        f.close()

    def load_from_file(self, file_name):
        f = open(file_name, 'r')
        a = f.read()
        f.close()
        j = json.loads(a)
        self.root.load_from_json(j)

if __name__ == '__main__':
    t = Tree()
    t.load_from_file('t.json')
    t.save_to_file('1.json')
