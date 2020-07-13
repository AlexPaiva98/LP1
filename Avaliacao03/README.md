# DIÁRIO 1.0

## Instalação no Linux

make

## Funções

1. Adicionar mensagem
2. Listar mensagens
3. Buscar mensagens por parâmetro

## Formas de Uso

1. Interativo: pode executar várias funções na execução do programa
2. Normal: pode executar uma função a cada chamada do programa

## Lista de comandos/ações

**Modo Interativo**
- ./diary interactive

**Modo Normal**
- ./diary add <mensagem>
- ./diary list <formato de saída>
- ./diary search <termo de busca>

***Exemplo de add(Modo Normal)***
Entrada: ./diary add "Mensagem 1"
Saída: Mensagem Adicionada

***Exemplo de list(Modo Normal)***
Entrada: ./diary list "[%d %t] %m"
Saída:  [01/10/2019 13:40:12] Mensagem 1
        [01/12/2019 17:05:55] Mensagem 2
        [03/12/2020 20:30:21] Mensagem 3

*Observação para formato de saída do list*:
- %d = DD/MM/YYYY
- %t = HH:MM:SS
- %m = MENSAGEM

***Exemplo de search(Modo Normal)***
Entrada: ./diary search "1"
Saída: [01/10/2019 13:40:12] Mensagem 1
