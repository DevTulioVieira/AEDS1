#Definindo lista
lista_simples_inteiro = [1, 2, 3, 8, 14, 4, 5]
#imprimindo lista
print(lista_simples_inteiro)

# Append()
#inserir 6 no fim da lista
lista_simples_inteiro.append(6)
print(lista_simples_inteiro)

# Insert()
#inserir 100 na posicao 2, lembranod que comça mo 0
lista_simples_inteiro.insert(2, 100)
print(lista_simples_inteiro)

# Len()
#tamanho da lista
print(len(lista_simples_inteiro))

#remove 3 da lista
lista_simples_inteiro.remove(3)

print(lista_simples_inteiro)

lista_simples_inteiro = [1, 2, 3, 8, 14, 4, 5]

print(lista_simples_inteiro)

print(lista_simples_inteiro[0:4]) # Cortar lista da posição 0 a 4 (sem incluir a 4)
print(lista_simples_inteiro[1:]) # Cortar lista da posição 1 em diante
print(lista_simples_inteiro[:3]) # Cortar lista do início até a posição 3 (sem incluir a 3)
nova_lista = lista_simples_inteiro[:3] # Criar uma nova lista com base no corte de outra lista
print(nova_lista)

intervalo = slice(1, 4) # Cortar a lista a partir da posição 1 até a 4 (sem incluir a 4)
print(lista_simples_inteiro[intervalo])
