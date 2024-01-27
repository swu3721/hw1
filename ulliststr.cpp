#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

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

// WRITE YOUR CODE HERE

//Push back
void ULListStr::push_back(const std::string& val) {
  //If the list is empty
  if (tail_ == nullptr) {
    //Make new Item
    tail_ = new Item();
    tail_->val[0] = val;
    tail_->last = 1;
    tail_->first = 0;
    tail_->prev = nullptr;
    tail_->next = nullptr;
    head_ = tail_;
    size_ = 1;
  } else if (tail_->last < ARRSIZE - 1) { //If there is open space in the array
    //push value to last value
    tail_->val[tail_->last] = val;
    //Update last
    tail_->last = tail_->last + 1;
    //No need to touch prev or next
    size_++;

  } else { //Array is full
    //Making new temp and adding it to the list
    //Similar to 1st case
    Item* temp = new Item();
    temp->val[0] = val;
    temp->first = 0;
    temp->last = 1;

    temp->next = nullptr;
    //Setting prev to point to former tail_ and former tails next
    tail_->next = temp;
    temp->prev = tail_;
    //Updating tail_ to point to end
    tail_ = temp;
    size_++;
  }
  
}

//Push front
void ULListStr::push_front(const std::string& val) {
  //If the list is empty
  if (head_ == nullptr) {
    //Make a new item for head
    head_ = new Item();
    //Add to last element of new item because simpler implementation
    head_->val[ARRSIZE-1] = val;
    head_->last = ARRSIZE;
    head_->first = head_->last -1;
    head_->next = nullptr;
    head_->prev = nullptr;
    tail_ = head_;
    size_ = 1;
  } else if (head_->first > 0) { //There is space in the array
    //Push val to front
    head_->val[head_->first - 1] = val;
    head_->first = head_->first - 1;
    size_++;
    //No need to touch prev or next
  } else { //there is no space in array
    //Make new head
    Item* temp = new Item();
    //Insert val at end of new item
    temp->val[ARRSIZE-1] = val;
    temp->first = ARRSIZE-1;
    temp->last = temp->first + 1;
    temp->prev = nullptr;
    //Make head prev of new head
    head_->prev = temp;
    //Make old head the next
    temp->next = head_;
    //Update head pointer
    head_ = temp;
    size_++;
  }
}

//Pop back
void ULListStr::pop_back() {
  //If list is empty, nothing
  if (empty() == true) {
    return;
  }
  //If tail is not empty
  if (tail_->last > tail_->first) {
    tail_->val[tail_->last] = "";
    //Pop back (Move last back one)
    tail_->last = tail_->last - 1;
    size_--;
    if (tail_->last == tail_->first) { //If tail is now empty and not the same as head delete tail and update
      Item* temp = tail_;
      tail_ = tail_->prev;
      delete temp;

      //If list empty now set it properly
      if (tail_ == nullptr) {
        head_ = nullptr;
      } else {
        //Update next to nullptr
        tail_->next = nullptr;
      }
    }

    
  }

  
}

//Pop front
void ULListStr::pop_front() {
  //If empty, nothing
  if (empty() == true) {
    return;
  }
  // If head is not empty
  if (head_->last > head_->first) {
    //Pop front (move first up 1)
    head_->val[head_->first] = "";
    head_->first = head_->first + 1;
    size_--;
    if (head_->first == head_->last) { //If there is no value in head anymore and not only item in list
      //Delete head and update
      Item* temp = head_;
      head_ = head_->next;
      delete temp;

      //If list empty set it properly
      if (head_ == nullptr) {
        tail_ = nullptr;
      } else {
        //Update next to nullptr
        head_->prev = nullptr;
      }
    }
  }
}

//Back
std::string const & ULListStr::back() const { //Assume not empty
  //last is exclusive
  return tail_->val[tail_->last - 1];
}

//Front
std::string const & ULListStr::front() const { //Assume not empty
  return head_->val[head_->first];
}

//getValAtLoc
std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (size_ == 0) {
    return nullptr;
  }

  //Iterate until location
  Item* currentItem = head_;
  size_t index = loc;

  //Check if head is null
  if (currentItem == nullptr) {
    return nullptr;
  }

  //While index is bigger than the available spaces in currentItem
  while (index >= currentItem->last - currentItem->first) {
    //Subtract available spaces from index
    index = index - (currentItem->last - currentItem->first);
    //Iterate to next item
    currentItem = currentItem->next;

    //Check if the location is beyond scope of list
    if (currentItem == nullptr) {
      return nullptr;
    }
  } 

  //Get the actual index in the correct item in list
  size_t valLoc = index + currentItem->first;
  //Return value
  return &currentItem->val[valLoc];

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
