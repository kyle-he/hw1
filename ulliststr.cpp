#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>

using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

/**
 * Adds a new value to the back of the list
 *   - MUST RUN in O(1)
 */
void ULListStr::push_back(const std::string& val) {
  size_ += 1;

  // will only be null at the same time
  if (head_ == NULL && tail_ == NULL) {
    // create a new item
    Item* newItem = new Item();
    newItem->val[0] = val;
    newItem->prev = NULL;
    newItem->next = NULL;

    // set both head and tail to new item
    head_ = newItem;
    tail_ = newItem;

    tail_->last += 1;
  } else {
    if (tail_->last == ARRSIZE) {
      Item* newItem = new Item();
      newItem->val[0] = val;
      newItem->prev = tail_;
      newItem->next = NULL;

      tail_->next = newItem;
      tail_ = newItem;

      tail_->first = 0;
      tail_->last = 1;
    } else {
      size_t freeIndex = tail_->last;
      tail_->val[freeIndex] = val;
      cout << "put " << val << " in local index " << freeIndex << endl;
      tail_->last += 1;
    }
  }
}

/**
 * Removes a value from the back of the list
 *   - MUST RUN in O(1)
 */
void ULListStr::pop_back(){
  if (empty()) {
    return;
  } else {
    if (tail_->last - tail_->first == 1) {
      // case 1: only 1 element left, delete node
      cout << "deleted NODE after deleting: " << tail_->val[tail_->last - 1] << endl;
      
      Item* oldTail = tail_;
      if (head_ == tail_) {
        head_ = NULL;
        tail_ = NULL;
      } else {
        tail_->prev->next = NULL;
        tail_ = tail_->prev;
      }
      // clean memory
      if (oldTail != NULL){
        delete oldTail;
      }
    } else {
      // case 2: delete an array element
      cout << "deleted: " << tail_->val[tail_->last - 1] << endl;
      tail_->val[tail_->last - 1] = "";
      tail_->last -= 1;
    }

    size_ -= 1;
  }
}
  
/**
 * Adds a new value to the front of the list.
 * If there is room before the 'first' value in
 * the head node add it there, otherwise, 
 * allocate a new head node.
 *   - MUST RUN in O(1)
 */
void ULListStr::push_front(const std::string& val) {
  size_ += 1;

  // will only be null at the same time
  if (head_ == NULL && tail_ == NULL) {
    // create a new item
    Item* newItem = new Item();
    newItem->val[ARRSIZE - 1] = val;
    newItem->prev = NULL;
    newItem->next = NULL;

    // set both head and tail to new item
    head_ = newItem;
    tail_ = newItem;

    head_->first = ARRSIZE - 1;
    head_->last = ARRSIZE;
  } else {
    if (head_->first == 0) {
      Item* newItem = new Item();
      newItem->val[ARRSIZE - 1] = val;
      newItem->next = head_;
      newItem->prev = NULL;

      head_->prev = newItem;
      head_ = newItem;
      head_->first = ARRSIZE - 1;
      head_->last = ARRSIZE;
    } else {
      size_t freeIndex = head_->first - 1;
      head_->val[freeIndex] = val;
      cout << "put " << val << " in local index " << freeIndex << endl;
      head_->first -= 1;
    }
  }
}

/**
 * Removes a value from the front of the list
 *   - MUST RUN in O(1)
 */
void ULListStr::pop_front() {
  if (empty()) {
    return;
  } else {
    if (head_->last - head_->first == 1) {
      // case 1: only 1 element left, delete node
      cout << "deleted NODE after deleting: " << head_->val[head_->last - 1] << endl;
      
      Item* oldHead = head_;
      if (head_ == tail_) {
        head_ = NULL;
        tail_ = NULL;
      } else {
        head_->next->prev = NULL;
        head_ = head_->next;
      }
      // clean memory
      if (oldHead != NULL){
        delete oldHead;
      }
    } else {
      // case 2: delete an array element
      cout << "deleted: " << head_->val[head_->first] << endl;
      head_->val[head_->first] = "";
      head_->first += 1;
    }

    size_ -= 1;
  }

}
  
/**
 * Returns a const reference to the back element
 *   - MUST RUN in O(1)
 */
std::string const& ULListStr::back() const {
  return tail_->val[tail_->last - 1];
}

/**
 * Returns a const reference to the front element
 *   - MUST RUN in O(1)
 */
std::string const& ULListStr::front() const {
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  size_t runningCounter = 0;
  Item* currItem = head_;
  if (0 <= loc && loc < size_) {
    while (currItem != NULL) {
      runningCounter += (currItem->last - currItem->first);
      if (runningCounter > loc) {
        size_t local_index = currItem->last - (runningCounter - loc);
        cout << "local index: " << local_index << endl;
        return currItem->val + local_index;
      }
      currItem = currItem->next;
    }
  }
  return NULL;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
