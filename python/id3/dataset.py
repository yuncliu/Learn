#!/usr/bin/env python3
import json
import math

class DataSet:
    def __init__(self, target_attr = None, data = None):
        self.entropy_all = 0
        self.target_attr = target_attr
        self.attr_entropy = dict()  #entropy for each attribute
        if data is not None:
            self.data = data
            self.process()
        else:
            self.data = list()

    def load_from_file(self, file_name):
        """read data from a json file"""
        f = open(file_name, 'r')
        self.data = json.load(f)
        f.close()
        self.process()

    def entropy(self):
        """get total entropy"""
        if self.entropy_all == 0:
            target_attr_space = dict()
            total = 0
            for i in self.data:
                t = i[self.target_attr]
                if t not in target_attr_space.keys():
                    target_attr_space[t] = 1
                else:
                    target_attr_space[t] = target_attr_space[t] + 1
                total = total + 1

            for k, v in target_attr_space.items():
                #print('{0} - {1}'.format(k, v))
                self.entropy_all = self.entropy_all -(v/total)*math.log2(v/total)

        return self.entropy_all

    def gain(self, attr):
        """calculate information gain for a single attribute"""
        attr_space = dict()
        for i in self.data:
            t = i[attr]
            if t not in attr_space.keys():
                attr_space[t] = dict()

            tmp = i[self.target_attr]
            if tmp not in attr_space[t].keys():
                attr_space[t][tmp] = 0

            attr_space[t][tmp] = attr_space[t][tmp] + 1

        sss = self.entropy_all
        for k, v in attr_space.items():
            s = 0
            total = 0
            for kk, vv in v.items():
                total = total + vv

            for kk, vv in v.items():
                s = s - (vv/total)*math.log2(vv/total)

            sss = sss - (total/len(self.data)) * s

        return sss

    def process(self):
        """calculate all the information gain for each attribute"""
        self.entropy()
        for i in self.data[0].keys():
            if i == self.target_attr:
                continue
            if i not in self.attr_entropy.keys():
                self.attr_entropy[i] = self.gain(i)

    def get_highest_entropy_attr(self):
        """get the attribute with has the highest information gain,
        this attribute should be the root for this dataset according
        to id3 algorithm
        """
        attr = None
        e = 0
        for k, v in self.attr_entropy.items():
            if e < v:
                attr = k
                e = v

        return attr

    def get_attr_values(self, attr):
        """get all values of one attriute"""
        t = list()
        for i in self.data:
            if i[attr] not in t:
                t.append(i[attr])

        return t

    def get_subset_by_attr(self, attr, value):
        "get a sub dataset based on a attrbute and one of its value"
        t = list()
        for i in self.data:
            if i[attr] == value:
                t.append(i)

        return DataSet(self.target_attr, t)


if __name__ == '__main__':
    d = DataSet('Play_ball')
    d.load_from_file('day.json')
    print('total entropy is {0}'.format(d.entropy()))
    print('entropy is {0}'.format(d.gain('Wind')))
    print('entropy is {0}'.format(d.gain('Outlook')))
    print('entropy is {0}'.format(d.gain('Humidity')))
    print('entropy is {0}'.format(d.gain('Temperature')))
    s = 0
    for k, v in d.attr_entropy.items():
        print('{0} \t\t {1}'.format(k, v))
        s = s + v

    print('highest attr is {0}'.format(d.get_highest_entropy_attr()))

    for i in d.get_attr_values('Outlook'):
        print(i)

    x = d.get_subset_by_attr('Outlook', 'Sunny')
    for i in x.data:
        print(i)
    print('Outook Sunny entropy is {0}'.format(x.entropy()))
