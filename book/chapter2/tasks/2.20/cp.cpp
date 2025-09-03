#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <string>
#include <limits>

class BB {
    std::map<std::string, int> vars_;
    std::vector<int> trans_;
    BB* pred_ = nullptr;
    std::vector<BB*> preds_;

public:
    BB(const std::map<std::string, int>& vars,
       const std::vector<int>& trans,
       BB* pred = nullptr):
    vars_(vars), trans_(trans), pred_(pred) {}

    void transitionFunc(std::vector<int>& values) const {
        std::transform(values.begin(), values.end(), 
                       trans_.begin(), values.begin(), 
                       std::plus<int>{});
    }

    void replace(std::string name, int val) {
        if (vars_.contains(name))
            vars_[name] = val;
    }

    std::vector<BB*> preds() {
        if (!preds_.empty()) {
            return preds_;
        }
        BB* cur = pred_;
        for (; cur != nullptr; cur = cur->pred_) {
            preds_.push_back(cur);
        }
        return preds_;
    }
};

int top = std::numeric_limits<int>::max();
int bot = std::numeric_limits<int>::min();

class Func {
    std::vector<std::string> allVars_;
    std::vector<BB*> allBloks_;

public:
    Func(const std::vector<std::string>& allVars,
         const std::vector<BB*>&  allBloks) :
    allVars_(allVars), allBloks_(allBloks_) {}

    const auto& allVars() const { return allVars_; };
    auto& allBloks() { return allBloks_; };
}; 

std::vector<int> join(const std::vector<int>& first, 
                      const std::vector<int>& second) 
{
    auto res = first;
    for (size_t i = 0; i < first.size(); ++i) {
        int f = first[i];
        int s = second[i];
        if (f == top || 
            s == top || 
            (f != bot && s != bot)) 
        { res[i] = top; }
        else { res[i] = f == bot ? s : f; }
    }
    return res;
} 


void propagateCopies(Func& f) {
    std::unordered_map<BB*, std::vector<int>> M;
    int N = f.allVars().size();
    
    for (auto* BB : f.allBloks()) 
        M[BB] = std::vector<int>(N, bot);
    
    bool changed = true;
    while (changed) {
        changed = false;
        for (auto bb : f.allBloks()) {
            std::vector<int> MIn(N, bot);
            for (auto* pred : bb->preds()) 
                MIn = join(MIn, M[pred]);
            bb->transitionFunc(MIn);
            if (MIn != M[bb]) {
                changed = true;
                M[bb] = MIn;
            } 
        }
    }

    for (auto* bb : f.allBloks()) {
        auto&& vals = M[bb];
        auto vars = f.allVars(); 
        for (size_t i = 0; i < N; ++i) {
            if (vals[i] != bot && vals[i] != top) {
                bb->replace(vars[i], vals[i]);
            }
        }
    }
}

int main() {

}
