#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 50

typedef struct data
{
	int dia, mes, ano;
} DATA;

typedef struct endereco
{
	char rua[MAX_CHAR], bairro[MAX_CHAR], cep[MAX_CHAR], cidade[MAX_CHAR],
			estado[MAX_CHAR];
	int numero;
} ENDERECO;

typedef struct paciente
{
	char nome[MAX_CHAR],
			cpf[MAX_CHAR],
			telefone[MAX_CHAR],
			email[MAX_CHAR],
			comorbidade[MAX_CHAR];

	ENDERECO endereco;

	DATA nascimento,
			diagnostico;

} PACIENTE;

void flush_in(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

void preenche_data(DATA *d)
{
	int temp;
	printf("\nInsira dia (Ex.: 01):\n");
	flush_in();
    scanf(" %d", &temp);
	d->dia = temp;
	printf("\nInsira mes (Ex.: 03):\n");
	flush_in();
    scanf(" %d", &temp);
	d->mes = temp;
	printf("\nInsira ano (Ex.: 1992):\n");
	flush_in();
    scanf(" %d", &temp);
	d->ano = temp;
}

void preenche_endereco(ENDERECO *e)
{
	int num;
	char temp[MAX_CHAR];
	
    printf("Insira rua:\n(Ex: Rua Sao Jorge)\n");
    flush_in();
	scanf(" %s", temp);
	strcpy(e->rua, temp);
	
	printf("\nInsira numero:\n");
	flush_in();
    scanf(" %d", &num);
	e->numero = num;
	printf("\nInsira bairro:\n");
	flush_in();
    scanf(" %s", temp);
	strcpy(e->bairro, temp);
	printf("\nInsira CEP (Ex.: 11460-500):\n");
	flush_in();
    scanf(" %s", temp);
	strcpy(e->cep, temp);
	printf("\nInsira cidade:\n");
	flush_in();
    scanf(" %s", temp);
	strcpy(e->cidade, temp);
	printf("\nInsira estado (Ex.: SP):\n");
	flush_in();
    scanf(" %s", temp);
	strcpy(e->estado, temp);
}

void preenche_paciente(PACIENTE *p)
{
	char temp[MAX_CHAR];
	
    printf("\nInsira nome completo:\n");
	flush_in();
    scanf(" %s", temp);
    strcpy(p->nome, temp);
    	
    printf("\nInsira CPF:\n(Ex.: 123.456.789-12)\n");
	flush_in();
    scanf(" %s", temp);
	strcpy(p->cpf, temp);
	

    printf("\nInsira telefone:\n(Ex.:(12)95678-8796)\n");
	flush_in();
    scanf(" %s", temp);
    strcpy(p->telefone, temp);
	

    printf("\nEndereco:\n");
	preenche_endereco(&p->endereco);
	
	printf("\nData de Nascimento:\n");
	
    preenche_data(&p->nascimento);
	printf("\nEmail -\n");
	printf("\nInsira e-mail: \n");
	flush_in();
    scanf(" %s", temp);
	strcpy(p->email, temp);
	printf("\nData do cadastramento - \n");
	
    preenche_data(&p->diagnostico);
	printf("\nComorbidade - (diabetes, obesidade, hipertensao, tuberculose...)?\n");
	printf("Insira comorbidade:\n");
	flush_in();
    scanf(" %s", temp);
	strcpy(p->comorbidade, temp);
}

void leitura_arquivo(PACIENTE *p)
{
	int total;
	FILE *arq;

	arq = fopen("pacientes.txt", "a");
	
	fprintf(arq,"\n Nome: %s, CPF: %s, Telefone: %s, Endereco: %s, Numero: %d, Bairro: %s, CEP: %s, Cidade: %s, Estado:  %s,",p->nome, p->cpf, p->telefone, p->endereco.rua, p->endereco.numero, p->endereco.bairro, p->endereco.cep, p->endereco.cidade, p->endereco.estado);
	fprintf(arq," Data de Nascimento: %02d / %02d / %02d,",p->nascimento.dia,p->nascimento.mes,p->nascimento.ano);
	fprintf(arq," E-mail: %s,",p->email);
	fprintf(arq," Data do Diagnostico: %02d / %02d / %02d,",p->diagnostico.dia,p->diagnostico.mes,p->diagnostico.ano);
	fprintf(arq," Comorbidade: %s",p->comorbidade);
	

	fclose(arq);
}

#define LOGIN "admin"
#define SENHA "admin"

int main(void)
{
	PACIENTE p;
	int oper;
	char entrada1[MAX_CHAR],
			entrada2[MAX_CHAR];

	printf("Insira o login: \n");
	scanf(" %s", entrada1);
	printf("\nInsira a senha: \n");
	scanf(" %s", entrada2);

	while (strcmp(entrada1, LOGIN) != 0 || strcmp(entrada2, SENHA) != 0)
    {
        printf("\nLogin e/ou Senha incorreta.\n");
		printf("Insira o login: \n");
		scanf(" %s", entrada1);
		printf("\nInsira a senha: \n");
		scanf(" %s", entrada2);
    }
	printf("\nSuccesso ao entrar\n");
	do
	{
		printf("\n\nDeseja cadastrar um paciente?\n");
		printf("1. Sim\n2. Nao\n");
		printf("\nInsira sua escolha: \n");
		flush_in();
        scanf(" %d", &oper);

        if (oper != 1 && oper != 2)
        {
		    while(oper != 1 &&  oper != 2)
            {
                printf("\nErro na digitação!\n");
                printf("Digite 1 para Sim, ou 2 para Nao\n");
                flush_in();
                scanf(" %d", &oper);
            }
            
            if(oper == 1)
            {
                preenche_paciente(&p);
			    leitura_arquivo(&p);
            }
            
		}
        else
        {
            if(oper==1)
            {
                preenche_paciente(&p);
                leitura_arquivo(&p);
            }
            else
            {
                oper=2;
            }   
        }

	} while (oper!= 2);
}