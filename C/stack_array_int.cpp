#include <iostream>

using namespace std;

class Stack
{
public:
  Stack(int limit=30)
  {
    m_top = -1;
    m_max = limit;
  }

  auto push(int item) -> Stack& 
  {
    if (is_full())
      cout << "stack is full\n";
    else
      m_arr[++m_top] = item;

    return *this;
  }

  auto pop() -> void
  {
    if (is_empty())
    {
      cout << "stack is empty\n";
      return;
    }

    m_top--;
  }

  auto peek() -> int
  {
    return m_arr[m_top];
  }

  auto top() -> int
  {
    return peek();
  }

  auto is_full() const -> bool 
  {
    return m_top == m_max;
  }

  auto is_empty() const -> bool
  {
    return m_top == -1;
  }

private:
  const static int MAX_SIZE = 100;
  int m_arr[MAX_SIZE];
  int m_top {-1};
  int m_max{MAX_SIZE};
};

int main()
{
  Stack s;
  s.push(1).push(2).push(3);
  s.pop();

  cout << s.top();

  return 0;
}
