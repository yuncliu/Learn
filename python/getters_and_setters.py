#!/usr/bin/python3
#-*- coding:utf-8 -*-
class Contact(object):
    def __init__(self, email = None):
        self._email = self.set_email(email)


    def set_email(self, e):
        if isinstance(e, str) and '@' in e:
            self._email = e
        else:
            print('invalid email address [%s]'%(e))

    def get_email(self):
        return self._email

    @property
    def xxx(self):
        return self._email

    @xxx.setter
    def xxx(self, e):
        if isinstance(e, str) and '@' in e:
            self._email = e
        else:
            print('invalid email address [%s]'%(e))

    email = property(get_email, set_email)



if __name__ == '__main__':
    x = Contact('abc')
    print(x.email)
    x.email='xxxxx'
    print(x.email)
    x.email = 'abcd@abcd'
    print(x.email)
    print(x.xxx)
    x.xxx='a@b'
    print(x.email)
