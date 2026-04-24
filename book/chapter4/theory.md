# Базовые оптимизации для SSA

Алгоритм

* Локальный - над одним бб
* Глобальный - над всеми бб ф-ции
* Межпроцедурный - между функциями/модулями

# Начало использования SSA

### Dead Code Elimination (DCE)

Удаляются i ssa-значения, которые не используются. Затем смотрятся значения j, которые использовал i, и если они после удаления i уже тоже неиспользоваются, то удаляются и они. И так до неподвижной точки.

![1776889527445](images/theory/1776889527445.png)

## фреймворк ssa

x1 - ssa value

* users(x1) - множество ssa value, которые используЮТ x1
* use(x1) - множество ssa value, которые используЕТ x1

Каждая инструкция порождает ssa value: можно переходить от инструкции к ssa value. (Instruction is Value)

# Граф зависимостей SSA

SSA graph - это граф, вершины которого - определения SSA-переменных, а ориент. ребро ее использование.

# Spare Constant Propagation

```python
LVs = LatticeSet()   // решётка для всех вершин SSA
WL = Stack()         // рабочий список (стек)

procedure scp():
    initlattice() // анализ листов - если конст. то он константа, иначе он overdef. (top), все нелистья - undef.
  
    for each E in ssa_edges:
        if LVs[def(E)] != top:
            WL.push(E)
  
    while not WL.empty(): // продвигаем константы по ребрам
        E = WL.pop()
        D = def(E)
        U = use(E)
        M = meet(LVs[D], LVs[U]) // meet(top, bot) = top
  
        if M == LVs[U]:
            continue
  
        LVs[U] = M
  
        for each I in ssa_users(U):
            WL.push(ssa_edge(U, I))
            OldVal = LVs[I.lhs()]
            NewVal = ssa_recompute_def(I.rhs(), U, M)
            LVs[I.lhs()] = NewVal
            propagate(I, NewVal)
```
