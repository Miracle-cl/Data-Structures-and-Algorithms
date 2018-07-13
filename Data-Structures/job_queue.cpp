#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::pair;
using std::make_pair;
using std::swap;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  // =====================  fast implementation =====================
  vector < pair<int, int> > data_;


  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  int Parent(int i) {
      return (i - 1) / 2;
  }

  int LeftChild(int i) {
      return 2 * i + 1;
  }

  int RightChild(int i) {
      return 2 * i + 2;
  }

  bool CompareWorker(pair<int, int> worker1, pair<int, int> worker2) {
      if (worker1.second != worker2.second)
          return worker1.second < worker2.second;
      else
          return worker1.first < worker2.first;
  }

  void SiftUp(int i) {
      while (i < num_workers_ && CompareWorker(data_[i], data_[Parent(i)])) {
          swap(data_[i], data_[Parent(i)]);
          i = Parent(i);
      }
  }

  void SiftDown(int i) {
      int maxindex = i;
      int l = 2 * i + 1;
      if (l < num_workers_ && CompareWorker(data_[l], data_[maxindex]))
          maxindex = l;

      int r = 2 * i + 2;
      if (r < num_workers_ && CompareWorker(data_[r], data_[maxindex]))
          maxindex = r;

      if (i != maxindex) {
          swap(data_[i], data_[maxindex]);
          SiftDown(maxindex);
      }
  }

  void ChangePriority(int idx, int priority) {
      int old_p = data_[idx].second;
      data_[idx] = make_pair(idx, priority);
      if (priority < old_p)
        SiftUp(idx);
      else
        SiftDown(idx);
  }



  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    // =====================  fast implementation =====================
    for (int i = 0; i < num_workers_; ++i) {
        data_.push_back(make_pair(i, 0));
    }

    for (int i = 0; i < jobs_.size(); ++i) {
        assigned_workers_[i] = data_[0].first;
        start_times_[i] = data_[0].second;
        ChangePriority(0, data_[0].second + jobs_[i]);
    }

    // =====================  naive implementation =====================
    // vector<long long> next_free_time(num_workers_, 0);
    // for (int i = 0; i < jobs_.size(); ++i) {
    //   int duration = jobs_[i];
    //   int next_worker = 0;
    //   for (int j = 0; j < num_workers_; ++j) {
    //     if (next_free_time[j] < next_free_time[next_worker])
    //       next_worker = j;
    //   }
    //   assigned_workers_[i] = next_worker;
    //   start_times_[i] = next_free_time[next_worker];
    //   next_free_time[next_worker] += duration;
    // }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
