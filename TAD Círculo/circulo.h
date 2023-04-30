typedef struct circ Circulo;

Circulo* circ_cria (float x1, float y1,float x2, float y2);

void circ_libera (Circulo* c);

void circ_acessa(Circulo* c, float* x1, float* y1,float* x2, float* y2);

void circ_atribui(Circulo* c, float x1, float y1,float x2, float y2);

char* circ_getCirculo(Circulo* c);

void circ_exibe(Circulo* c);

float circ_perimetro(Circulo* c);

float circ_area(Circulo* c);