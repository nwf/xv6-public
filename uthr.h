/* Userland spinlock public API */

struct uspin;	/* forward declaration */
int  uspin_init   (struct uspin *sem);
void uspin_acquire(struct uspin *sem);
void uspin_release(struct uspin *sem);
void uspin_destroy(struct uspin *sem);

/* Userland semaphore public API */

struct usem;	/* forward declaration */
int  usem_init   (struct usem *sem, uint initial_count);
void usem_acquire(struct usem *sem);
void usem_release(struct usem *sem);
void usem_destroy(struct usem *sem);

/* Userland thread library public API */
int  uthr_init(unsigned int stack_size);
int  uthr_create(void (*f)(void *), void *arg);
void uthr_exit(void *baton);
int  uthr_join(int tid, void **hand);

/* Thread safe wrappers! */
void *uthr_malloc(int);
void  uthr_free(void *);
