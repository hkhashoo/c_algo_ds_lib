# Deque (Double-Ended Queue) Data Structure

A deque is a data structure that allows insertion and deletion of elements 
from both ends (front and rear). It is a generalized form of a queue that 
supports operations at both ends efficiently. Deques are commonly used in 
scenarios where elements need to be accessed or modified from both ends.
<br></br>

* Container for void pointer
```
typedef struct Node {
	void* data;
	struct Node *next;
	struct Node *prev;
} Node;
```
<br></br>
* Stack structure
```
typedef struct Queue{
	QueueContainer * rear;
	QueueContainer *front;
	int length;
}Queue;
```
### At no point does the library need you to instantiate these manually. There are functions for all necessary operations
<br></br>

## Getting a deque object

    * Function : `newDeque()`

        Description : Get a new queue object for performing operations
        
        Arguments : *None*
        
        Return Value : Queue*
<br></br>

## Methods

### 1. `pushRear(item)`
Adds an element to the rear (right) end of the deque.

- **Parameters**:
    - `item`: The element to be added to the deque.
- **Raises**:
    - `OverflowError`: If the deque is full (in case of a bounded deque).

<br></br>

### 2. `pushFront(item)`
Adds an element to the front (left) end of the deque.

- **Parameters**:
    - `item`: The element to be added to the deque.
- **Raises**:
    - `OverflowError`: If the deque is full (in case of a bounded deque).

<br></br>

### 3. `popRear()`
Removes and returns the element from the rear (right) end of the deque.

- **Returns**:
    - The element removed from the rear.
- **Raises**:
    - `IndexError`: If the deque is empty. Returns -1 with a notification that deque is empty.

<br></br>

### 4. `popFront()`
Removes and returns the element from the front (left) end of the deque.

- **Returns**:
    - The element removed from the front.
- **Raises**:
    - `IndexError`: If the deque is empty.

<br></br>

### 5. `peekRear()`
Returns the element at the rear (right) end of the deque without removing it.

- **Returns**:
    - The element at the rear.
- **Raises**:
    - `IndexError`: If the deque is empty.

<br></br>

### 6. `peekFront()`
Returns the element at the front (left) end of the deque without removing it.

- **Returns**:
    - The element at the front.
- **Raises**:
    - `IndexError`: If the deque is empty.

<br></br>

### 7. `isEmpty()`
Checks if the deque is empty.

- **Returns**:
    - `True` if the deque is empty, `False` otherwise.

<br></br>

### 8. `getLength()`
Returns the number of elements currently in the deque.

- **Returns**:
    - An integer representing the number of elements in the deque.

<br></br>

### 9. `freeDeque()`
Removes all elements from the deque, leaving it empty.

<br></br>

### 10. `displayDeque()`
Displays all the elements in the deque from front to rear.

- **Returns**:
    - Nothing, Prints all the elements from the front to the rear of the Deque.

<br></br>

## Usage
Deques are versatile and can be used in various applications such as:
- Implementing queues or stacks.
- Sliding window problems.
- Maintaining order of elements with efficient insertions and deletions.
