
# Documentação projeto ITP

O projeto a seguir se consiste em 2 funções.

   - Gerar um arquivo PBM no padrão EAN-8 a partir de 8 dígitos

   - Extrai informações do arquivo gerado e afirma se o código é válido. (Não concluído)

Ele se organiza juntando as structs, funções, strings, etc, no arquivo ``barcode_utils.h``.


Uso: Compile o arquivo ``generate_barcode.cpp`` e ``extract_barcode.cpp``, escolha o nome que desejar. Veja abaixo um exemplo:
```
g++ generate_barcode.cpp -o gerar

g++ extract_barcode.cpp -o testar

```
Executar o arquivo ``generate_barcode.cpp`` pedirirá 8 digitos, eles devem ser inteiros, após inseri-los o programa irá gerar ``barcode.pbm``, para visualizar bastar abri-lo ou use programas de terceiros caso não esteja no linux.

Executar o arquivo ``extract_barcode.cpp`` fará com que ele leia o conteúdo do ``barcode.pbm``, infelizmente ele lê os 8 primeiros dígitos ao em vez dos dígitos inseridos para a criação do ``barcode.pbm``.


Obrigado pela atenção.
