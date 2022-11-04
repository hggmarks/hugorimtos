
## O que danado é Big Oh?

Sendo simplista, é uma forma de categorizar o tempo e/ou memória que um algorimto precisa para ser executado baseado no tamanho da entrada.

Coisas que o big Oh não te diz:
* tempo de execução;
* Quanta memória vai consumir;
* Quantos mips ou flops;

---
#### Logo, não se trata de uma medida exata, mas porque usamos ela?
* Por ser uma boa forma generalizar como um algortimo cresce em consumo de tempo e espaço baseado no tamanho da entrada.
* Ajuda na tomada de decisão a respeito de que tecnica usar, ja que conhecemos como é a performance dos algortimos.

---

##### Exemplo
> Quando alguem diz "Tal algoritmo é Óh de N"

  isso significa que o algoritmo cresce de forma linear com a entrada

---

![grafico de ordem de crescimento de algoritmos](media/order-of-growth-graph.png)

---

### Um pequeno exemplo 

```typescript
function sum_char_codes(s: string): number {
	let sum = 0;
	for (let i = 0; i < s.length; ++i) { 
		sum += s.charCodeAt(i);
	} 
	return sum;
}
```

#### Pra quem ja conhece, é traquilinho
Pra quem não manja ou nunca avaliou uma função, talvez seja um mistério completo, talvez não.

---

### Como isso funciona na vida real?
Consumo de memória não pode crescer indefinidamente ja que memória é limitada. Mas quando o assunto é algoritmos, esse tópico é deixado de lado (na maioria dos casos).

Em linguagens como Go ou ***JAVASCRIPT*** preços muito altos são pagos em memória, causando paradas na execução dos programas só pra limpar a memória (garbage collection).

---

### Voltando ao exemplo anterior

```typescript
function sum_char_codes(s: string): number {
	let sum = 0;
	for (let i = 0; i < s.length; ++i) { 
		sum += s.charCodeAt(i);
	} 
	return sum;
}
```


O truque mais simples é procurar por laços de repetição (loops)

---

### Logo se o codigo fosse assim a complexidade seria?

Se o anterior foi O(N), esse aqui é?

```typescript
function sum_char_codes(s: string): number {
	let sum = 0;

	for (let i = 0; i < s.length; ++i) { 
		sum += s.charCodeAt(i);
	} 

	for (let i = 0; i < s.length; ++i) { 
		sum += s.charCodeAt(i);
	} 

	return sum;
}
```

---

![meme de complexidade com gato](media/complexity-meme.png)

---

### Conceitos importantes
* Descanrtamos constantes multiplicando N
* E isso faz sentido, estamos vendo o pior caso do algoritmo, o limite superior, então em algum momento a constante se torna irrelevante.

saca só:

---

![grafico de ordem de crescimento de algoritmos](media/order-of-growth-graph.png)

---

N = 1, O(10N) = 10, O(N²) = 1

N = 5, O(10N) = 50, O(N²) = 25

N = 100, O(10N) = 1,000, O(N²) = 10,000 // 10x maior 

N = 1000, O(10N) = 10,000, O(N²) = 1,000,000 // 100x maior 

N = 10000, O(10N) = 100,000, O(N²) = 100,000,000 // 1000x maior 

---

### Existem diferenças praticas e teoricas

No exeplo de cima apesar de 10N ser mais rapido que N², isso só se mantem para entradas muito pequenas, se sua entrada for ser pequena, beleza!

---
### Outro exemplo

```typescript
function sum_char_codes(n: string): number { 

	let sum = 0; 
	
	for (let i = 0; i < n.length; ++i) { 
	
		const charCode = n.charCodeAt(i); 
		 
		if (charCode === 69) { 
			// E Maiusculo
			return sum; 
		} 
		
		sum += charCode; 
	} 
	return sum; 
}
```

---
### Big Oh é sempre PIOR CASO

Se na string tiver um "E" antes do final da string, OTIMO, ele vai terminar de executar mais rapido, mas ainda vamos considerar sempre o pior caso para determinar complexidade ou seja.

CONTINUA O(N).

---
### Outro exemplos

#### O(N²)

```typescript
function sum_char_codes(n: string): number {
    let sum = 0;
    for (let i = 0; i < n.length; ++i) {
        for (let j = 0; j < n.length; ++j) {
            sum += charCode;
        }
    }

    return sum;
}
```

---

#### O(N³)

```typescript
function sum_char_codes(n: string): number {
    let sum = 0;
    for (let i = 0; i < n.length; ++i) {
        for (let j = 0; j < n.length; ++j) {
            for (let k = 0; k < n.length; ++k) {
                sum += charCode;
            }
        }
    }
    return sum;
}
```

---

#### O(n log n)
É o caso do quickSort, que veremos no futuro

#### O(log n)
Binary Search Tree (Arvores de busca binária)