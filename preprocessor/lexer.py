import ply.lex as lex

tokens = (
    'L_PAREN',
    'R_PAREN',
    'NS_DELIM',
    'ASTERISK',
    'AMBERSAND',
    'L_ANGLE_BRACKET',
    'R_ANGLE_BRACKET',
    'EQ_SIGN',
    'SEMICOLON',
    'COMMA',
    'CHAR',
    'WCHAR_T',
    'BOOL',
    'SHORT',
    'INT',
    'LONG',
    'SIGNED',
    'UNSIGNED',
    'FLOAT',
    'DOUBLE',
    'VOID',
    'CONST',
    'STRING_LITERAL',
    'NUMBER_LITERAL',
    'IDENTIFIER'
)

reserved = {
    'char': 'CHAR',
    'wchar_t': 'WCHAR_T',
    'bool': 'BOOL',
    'short': 'SHORT',
    'int': 'INT',
    'long': 'LONG',
    'signed': 'SIGNED',
    'unsigned': 'UNSIGNED',
    'float': 'FLOAT',
    'double': 'DOUBLE',
    'void': 'VOID',
    'const': 'CONST',
}

def build_lexer() -> lex.Lexer:
    t_L_PAREN         = r'\('
    t_R_PAREN         = r'\)'
    t_NS_DELIM        = r'::'
    t_ASTERISK        = r'\*'
    t_AMBERSAND       = r'&'
    t_L_ANGLE_BRACKET = r'<'
    t_R_ANGLE_BRACKET = r'>'
    t_EQ_SIGN         = r'='
    t_SEMICOLON       = r';'
    t_COMMA           = r','
    t_VOID            = r'void'
    t_STRING_LITERAL  = r'"(.|\\")*"'
    t_NUMBER_LITERAL  = r'[0-9]+(l|ll|u|ul|ull)?|[0-9]*\.[0-9]+(d|f)?'

    def t_IDENTIFIER(t):
        r'([a-z]|[A-Z])+([a-z]|[A-Z]|[0-9]|_)*'
        t.type = reserved.get(t.value, 'IDENTIFIER')
        return t

    def t_newline(t):
        r'\n+'
        t.lexer.lineno += len(t.value)

    t_ignore = ' \t'

    return lex.lex()