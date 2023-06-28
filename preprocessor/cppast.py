class Node:
    def _obj_str(*args, **kwargs):
        name = self.__class__.__name__
        args_str = list(map(lambda x: str(x), args)).join(', ')
        kwargs_str = ''
        for i, (k, v) in enumerate(kwargs.items()):
            kwargs_str += ' ' + k + ': ' + str(v)
            if i != len(kwargs)-1:
                kwargs_str += ','
        return f'#{name}({args_str}{kwargs_str})'

    def __str__(self):
        return self._obj_str()

class SimpleDeclaration(Node):
    def __init__(self, decl_specifier_seq: list, init_declarator_list: list):
        self.decl_specifier_seq = decl_specifier_seq
        self.init_declarator_list = init_declarator_list

    def __str__(self):
        return self._obj_str(self.decl_specifier_seq, self.init_declarator_list)

class DeclSpecifier(Node):
    def __init__(self, val):
        self.val = val

    def __str__(self):
        return self._obj_str(self.val)

class FunctionSpecifier(Node):
    def __init__(self, val: str):
        self.val = val

    def __str__(self):
        return self._obj_str(self.val)

class TypeSpecifier(Node):
    def __init__(self, val):
        self.val = val

    def __str__(self):
        return self._obj_str(self.val)

class StorageClassSpecifier(Node):
    def __init__(self, val: str):
        self.val = val

    def __str__(self):
        return self._obj_str(self.val)

class CvQualifier(Node):
    def __init__(self, val: str):
        self.val = val

    def __str__(self):
        return self._obj_str(self.val)

