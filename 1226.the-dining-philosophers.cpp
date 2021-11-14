/*
 * @lc app=leetcode id=1226 lang=cpp
 *
 * [1226] The Dining Philosophers
 */

// @lc code=start
class DiningPhilosophers {
  int n = 5;
  vector<mutex> forkLocks;

 public:
  DiningPhilosophers() : forkLocks(n) {}

  void wantsToEat(int philosopher, function<void()> pickLeftFork,
                  function<void()> pickRightFork, function<void()> eat,
                  function<void()> putLeftFork, function<void()> putRightFork) {
    int left = philosopher;
    int right = (philosopher + 1) % n;
    if (philosopher == 4) {
      forkLocks[right].lock();
      forkLocks[left].lock();
      pickRightFork();
      pickLeftFork();
    } else {
      forkLocks[left].lock();
      forkLocks[right].lock();
      pickLeftFork();
      pickRightFork();
    }
    eat();
    if (philosopher == 4) {
      putLeftFork();
      putRightFork();
      forkLocks[left].unlock();
      forkLocks[right].unlock();
    } else {
      putRightFork();
      putLeftFork();
      forkLocks[right].unlock();
      forkLocks[left].unlock();
    }
  }
};
// @lc code=end
