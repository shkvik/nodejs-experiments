#include <iostream>
#include <stack>
#include <queue>

typedef enum {
  EL_RUN,
  EL_EXIT,
} loop_status;


class event_loop {

public:
  int run() {
    while (status != EL_EXIT) {
      call_stack->

      
    }
  }

private:
  int executor() {

  }


private:
  loop_status status;

private:
  std::unique_ptr<call_stack> call_stack;
  std::unique_ptr<micro_queue> micro_queue;
  std::unique_ptr<macro_queue> macro_queue;
};



class call_stack {
private:
  std::stack<sync_task> stack;

public:
  inline size_t size() const noexcept {
    return stack.size();
  }
};

class macro_queue {
  using macro_task_q = std::unique_ptr<std::queue<macro_task>>;
private:
  macro_task_q queue;
};

class micro_queue {
  using micro_task_q = std::unique_ptr<std::queue<micro_task>>;
private:
  micro_task_q queue;
};

class task {

};

class sync_task : public task {

};

class micro_task : public task {

};

class macro_task : public task {

};


int main() {
  std::cout << "Hello World!\n";
}