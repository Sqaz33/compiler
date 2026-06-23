# Работа с функциями

### Call grap

Граф вызовов фунцкий, где вершины - ф-ции, дуги - вызовы

Могут быть 2 типа дуг - индеректные и деректные вызовы.

### DFEN (N - naive)

Удаление функций, которые не используются, и которые не входят в интерфейс модуля.

Алгоритм как в DCE

![1782153679410](images/theory/1782153679410.png)

Синим - static. Можно удалить bar. Но не foo.

Не удалит, если static вызывают друг дргуа.

## Продвижение информации

1. клонирование функции
2. ```cpp
   void propagate_arg(Function F, int ArgNo, auto Val) {
       auto Def = F.get(ArgNo);
       if (!static(F))
           return;
       for (auto U : ssa_users(Def))
           replace_uses_with(U, Def, Val);
       if (F.cguses.empty())
           F.remove_arg(ArgNo);
       sccp(F);
   }

   ```

## RTA

```python
build_virtual_calls_targets(CallGraph CG,
                            Function Root) {
    Stack<Function> Methods;
    List<Function> CallSites;
    Vector<List<Function>> VCT(CG.size());
    auto Classes = GetFEClassesInfo();
    for (auto M : CG) Visited[M] = false;
    for (auto C : Classes) Live[C] = false;
    Methods.push(Root);

    while (!Methods.empty()) {
        auto M = Methods.pop();
        if (Visited[M]) continue;

        for (auto CS : CG.callsites(M)) {
            if (CS.virtual()) {
                VCT[M].add(CS.static_type());
                CallSites.add(CS);
                continue;
            }

            for (auto TM : CG.targets(CS))
                Methods.push(TM);
        }

        for (auto C : GetFEInstantiations(M)) {
            if (Live[C]) continue;
            Live[C] = true;
            for (auto CS : CallSites) {
                TM = C.dynamic_target(CS);
                if (!TM) continue;
                VCT[M].add(TM);
                Methods.push(TM);
            }
        }

        Visited[M] = true;
    }

    return VCT;
}
```
