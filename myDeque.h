typedef struct deque Deque;

#define DEQUE_FRONT (1)
#define DEQUE_BACK (0)

#define DEQUE_EMPTY ('\0')  /* returned by dequePop, dequePeek, dequePeekNext if deque is empty */

/* return a new deque with specified value */
Deque *dequeCreate(char value);

/* change value of deque to specified value */
void dequeWrite(Deque *d, char value);

/* push new value onto direction side of deque d */
void dequePush(Deque *d, int direction, char value);

/* pop and return first value on direction side of deque d */
/* returns DEQUE_EMPTY if deque is empty */
char dequePop(Deque *d, int direction);

/* return value of deque d */
/* returns DEQUE_EMPTY if deque is empty */
char dequePeek(Deque *d);

/* returns dequePeek value of next Deque */
char dequePeekNext(Deque *d, int direction);

/* returns next deque in specified direction of d */
Deque *dequeNext(Deque *d, int direction);

/* return 1 if deque contains no elements, 0 otherwise */
int dequeIsEmpty(Deque *d);

/* free space used by a deque */
void dequeDestroy(Deque *d);

/* convert + to 1 and - to 0 */
int convertDirection(char dir);
