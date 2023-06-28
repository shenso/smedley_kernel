from ply import yacc
from lexer import tokens
import cppast as cst

def p_simple_declaration(p):
    'simple_declaration : decl_specifier_seq init_declarator_list SEMICOLON'
    p[0] = cst.SimpleDeclaration(p[1], p[2])

def p_decl_specifier_seq(p):
    '''
    decl_specifier_seq : decl_specifier_seq decl_specifier
                       | decl_specifier
    '''
    if len(p) == 2:
        p[0] = [p[1]]
    else:
        p[0] = p[1]
        p[0].append(p[2])

def p_init_declarator_list(p):
    '''
    init_declarator_list : init_declarator
                         | init_declarator_list COMMA init_declarator
    '''
    if len(p) == 2:
        p[0] = [p[1]]
    else:
        p[0] = p[1]
        p[0].append(p[3])

def p_decl_specifier(p):
    'decl_specifier : function_specifier | type_specifier | storage_class_specifier | FRIEND | TYPEDEF'
    p[0] = cst.DeclSpecifier(p[1])

def p_init_declarator(p):
    'init_declarator : declarator'
    p[0] = p[1]

def p_function_specifier(p):
    'function_specifier : INLINE | VIRTUAL | EXPLICIT'
    p[0] = cst.FunctionSpecifier(p[1])

def p_type_specifier(p):
    'type_specifier : simple_type_specifier | elaborated_type_specifier | cv_qualifier'
    p[0] = cst.TypeSpecifier(p[1])

def p_storage_class_specifier(p):
    'storage_class_specifier : AUTO | REGISTER | STATIC | EXTERN | MUTABLE'
    p[0] = cst.StorageClassSpecifier(p[1])

def p_declarator(p):
    'declarator : direct_declarator | ptr_operator declarator'
    pass

def p_simple_type_specifier(p):
    '''
    simple_type_specifier : NS_DELIM nested_name_specifier type_name
                          | NS_DELIM type_name
                          | nested_name_specifier type_name
                          | type_name
                          | NS_DELIM nested_name_specifier TEMPLATE template_id
                          | nested_name_specifier TEMPLATE template_id
                          | CHAR
                          | WCHAR_T
                          | BOOL
                          | SHORT
                          | INT
                          | LONG
                          | SIGNED
                          | UNSIGNED
                          | FLOAT
                          | DOUBLE
                          | VOID
    '''
    if len(p) == 2:
        p[0] = p[1]
    else:
        pass # TODO: capture

def p_elaborated_type_specifier(p):
    '''
    elaborated_type_specifier : class_key NS_DELIM nested_name_specifier IDENTIFIER
                              | class_key NS_DELIM IDENTIFIER
                              | class_key nested_name_specifier IDENTIFIER
                              | class_key IDENTIFIER
                              | ENUM NS_DELIM nested_name_specifier IDENTIFIER
                              | ENUM NS_DELIM IDENTIFIER
                              | ENUM nested_name_specifier IDENTIFIER
                              | ENUM IDENTIFIER
                              | TYPENAME NS_DELIM nested_name_specifier IDENTIFIER
                              | TYPENAME nested_name_specifier IDENTIFIER
                              | TYPENAME NS_DELIM nested_name_specifier TEMPLATE template_id
                              | TYPENAME nested_name_specifier TEMPLATE template_id
                              | TYPENAME NS_DELIM nested_name_specifier template_id
                              | TYPENAME nested_name_specifier template_id
    '''
    pass

def p_cv_qualifier(p):
    'cv_qualifier : CONST | VOLATILE'

def p_direct_declarator(p):
    '''
    direct_declarator : declarator_id |
                        direct_declarator L_PAREN parameter_declaration_clause R_PAREN |
                        direct_declarator L_PAREN parameter_declaration_clause R_PAREN cv_qualifier_seq |
                        direct_declarator L_PAREN parameter_declaration_clause R_PAREN cv_qualifier_seq exception_specification
    '''
    pass

def build_parser():
    return yacc.yacc()
