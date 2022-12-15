

void advance() { tok = getToken(); }
void eat(enum token t) {if (tok==t) advance(); else error();}


void parser() {
    S();
}

void S(void) {
    switch(tok) {
        case 'if':
            eat("IF"); E(); eat("THEN"); S();
            eat("ELSE"); S(); 
            break;
        case 'BEGIN': 
            eat("BEGIN");   
            S(); 
            L(); 
            break;
        case 'PRINT': eat("PRINT"); E(); break;
        default:
        error();
    }
}

void L(void) {
    switch(tok) {
        case 'END':
            eat('END'); 
            break;
        case 'SEMI': 
            eat('SEMI'); S(); L(); 
            break;
        default:
            error();
    }
}

void E(void) {
    eat('NUM'); eat('EQ'); eat('NUM'); 
}