### OH YEAH Tamo ficando bons nisso

Esse algoritmo pode parecer estranho a principio mas é genial. BUSCA BINÁRIA.

---

### OK Está ordenado, mas e aí?
Vamos finjir que a entrada foi ordenada por alguma entidade superior. Como podemos buscar nessa array?

---

### Sim é ela, a hora de voltar para o quadro

---

### Qual o Big Oh disso?

---

### Qual o Big Oh disso?

* Outro truque basico de Big Oh é: Se a entrada diminui pela metade após cada passo, provavelmente deve ser algo com log N; 
* O( Log N ) ou O( N log N );

---

### Isso é BUSCA BINARIA
Um dos maiores de todos os tempos

---

### HORA DE CODAR

```python
Algorithm: BS(A[0..n-1],l,r,K))
 1 if r ≥ l then
 2     m ← b(l + r)/2c;
 3     if K = A[m] then
 4         return m;
 5     else if K < A[m] then
 6         return BS(A, l, m − 1, K);
 7     else
 8         return BS(A, m + 1, r, K);
 9 else
10 return −1;
```

---
