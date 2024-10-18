#include <iostream>
#include <stack>
#include <queue>
#include <functional>

typedef enum {
  EL_RUN,
  EL_EXIT,
} loop_status;


class event_loop {

public:
  int run() {
    while (status != EL_EXIT) {
      execute_sync_tasks();
      execute_micro_tasks();
      execute_macro_tasks();
    }
  }

private:
  void execute_sync_tasks() {

  }
  void execute_micro_tasks() {

  }
  void execute_macro_tasks() {

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
public:
  void push(micro_task&& micro_t) {
    queue->push(std::move(micro_t));
  }

private:
  micro_task_q queue;
};


class micro_task : public task {

};

template<typename type, typename... args>
class promise : public micro_task {
  using call_back_t = std::function<type(args...)>;
public:
  promise(micro_queue& mq, call_back_t&& cb) :
    call_back(std::move(cb)),
    status(PENDING)
  {
    mq.push(std::move(*this));
  }

public: 
  int resolve() {
    status = FINISHED;
  }
private:
  call_back_t call_back;

private:
  typedef enum : uint32_t{
    PENDING,
    FINISHED,
    REJECTED
  } promise_status;

  promise_status status;
};

class task {

};

class sync_task : public task {
  // create micro_task
};



class macro_task : public task {

};


int testFunction(int a) {
  std::cout << "Hello World!\n";
}

int main() {
  std::cout << "Hello World!\n";
}