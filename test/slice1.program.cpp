CBMC version 5.1 64-bit x86_64 macos
Parsing slice.c
Converting
Type-checking slice
Generating GOTO Program
Adding CPROVER library
Function Pointer Removal
Partial Inlining
Generic Property Instrumentation
Starting Bounded Model Checking
Adding SC constraints
size of program expression: 322 steps
no slicing due to threads
Generated 1 VCC(s), 1 remaining after simplification

VERIFICATION CONDITIONS:

file slice.c line 15 function p3
assertion
{-1} __CPROVER_pipe_count#1 == 0
{-2} y#1 == 1
{-3} __CPROVER_rounding_mode!0#1 == 0
{-4} __CPROVER_thread_id!0#1 == 0
{-5} x#1 == 1
{-6} __CPROVER_threads_exited#1 == ARRAY_OF(FALSE)
{-7} __CPROVER_next_thread_id#1 == 0
{-8} __CPROVER_deallocated#1 == NULL
{-9} __CPROVER_dead_object#1 == NULL
{-10} __CPROVER_malloc_object#1 == NULL
{-11} __CPROVER_malloc_size#1 == 0
{-12} __CPROVER_malloc_is_new_array#1 == FALSE
{-13} __CPROVER_memory_leak#1 == NULL
{-14} thread!0@1#1 == &t2!0@1
{-15} attr!0@1#1 == ((struct _opaque_pthread_attr_t *)NULL)
{-16} start_routine!0@1#1 == (void * (*)(void *))p2
{-17} arg!0@1#1 == NULL
{-18} __CPROVER_next_thread_id#2 == 1
{-19} this_thread_id!0@1#2 == 1
{-20} t2!0@1#2 == (struct _opaque_pthread_t *)1
{-21} start_routine!0@1#1 == (void * (*)(void *))p2
{-22} arg!0@1#1 == NULL
{-23} id!0@1#1 == 1
{-24} start_routine!1@0#1 == (void * (*)(void *))p2
{-25} arg!1@0#1 == NULL
{-26} id!1@0#1 == 1
{-27} __CPROVER_rounding_mode!1#1 == 0
{-28} __CPROVER_thread_id!1#1 == 0
{-29} main#return_value!1#1 == 0
{-30} pthread_create#return_value!1#1 == 0
{-31} pthread_join#return_value!1#1 == 0
{-32} p2#return_value!1#1 == NULL
{-33} p3#return_value!1#1 == NULL
{-34} pthread_create#return_value!0#1 == 0
{-35} this_thread_id!0@1#4 == 1
{-36} thread!0@2#1 == &t3!0@1
{-37} attr!0@2#1 == ((struct _opaque_pthread_attr_t *)NULL)
{-38} start_routine!0@2#1 == (void * (*)(void *))p3
{-39} arg!0@2#1 == NULL
{-40} __CPROVER_next_thread_id#4 == (FALSE || FALSE ? __CPROVER_next_thread_id#2 : __CPROVER_next_thread_id#3)
{-41} __CPROVER_next_thread_id#5 == 1 + __CPROVER_next_thread_id#4
{-42} this_thread_id!0@2#2 == __CPROVER_next_thread_id#5
{-43} t3!0@1#2 == (struct _opaque_pthread_t *)this_thread_id!0@2#2
{-44} start_routine!0@2#1 == (void * (*)(void *))p3
{-45} arg!0@2#1 == NULL
{-46} id!0@2#1 == this_thread_id!0@2#2
{-47} start_routine!2@0#1 == (void * (*)(void *))p3
{-48} arg!2@0#1 == NULL
{-49} id!2@0#1 == id!0@2#1
{-50} __CPROVER_rounding_mode!2#1 == 0
{-51} __CPROVER_thread_id!2#1 == 0
{-52} main#return_value!2#1 == 0
{-53} pthread_create#return_value!2#1 == 0
{-54} pthread_join#return_value!2#1 == 0
{-55} p2#return_value!2#1 == NULL
{-56} p3#return_value!2#1 == NULL
{-57} pthread_create#return_value!0#2 == 0
{-58} this_thread_id!0@2#4 == this_thread_id!0@2#2
{-59} thread!0@1#2 == t3!0@1#2
{-60} value_ptr!0@1#2 == ((void **)NULL)
{-61} \guard#1 == !(__CPROVER_next_thread_id#6 >= (unsigned long int)thread!0@1#2)
{-62} \guard#2 == ((unsigned long int)thread!0@1#2 == 0)
{-63} thread!0@1#4 == (struct _opaque_pthread_t *)1
{-64} value_ptr!0@1#4 == ((void **)NULL)
{-65} \guard#3 == __CPROVER_next_thread_id#7 < 1
{-66} main#return_value!0#1 == nondet_symbol(symex::nondet0)
{-67} __CPROVER_thread_id!1#2 == 1
{-68} va_arg0#1 == NULL
{-69} y#2 == 1
{-70} y#3 == 3
{-71} x#2 == 5
{-72} p2#return_value!1#2 == nondet_symbol(symex::nondet1)
{-73} __CPROVER_threads_exited#5 == __CPROVER_threads_exited#4 WITH [1:=TRUE]
{-74} __CPROVER_thread_id!2#2 == id!2@0#1
{-75} va_arg0#1 == NULL
{-76} yt!2@1#2 == y#4
{-77} xt!2@1#2 == x#3
{-78} yt!2@1#3 == y#5
{-79} p3#return_value!2#2 == nondet_symbol(symex::nondet2)
{-80} __CPROVER_threads_exited#7 == __CPROVER_threads_exited#6 WITH [(long int)id!2@0#1:=TRUE]
{-81} __CPROVER_threads_exited#2 == __CPROVER_threads_exited#1 || !choice_rf0
{-82} __CPROVER_threads_exited#2 == __CPROVER_threads_exited#5 || !choice_rf1
{-83} !(__CPROVER_threads_exited#5$wclk$8 >= __CPROVER_threads_exited#2$rclk$8) || !choice_rf1
{-84} __CPROVER_threads_exited#2 == __CPROVER_threads_exited#7 || !choice_rf2
{-85} !(__CPROVER_threads_exited#7$wclk$8 >= __CPROVER_threads_exited#2$rclk$8) || !choice_rf2
{-86} \guard#1 || \guard#2 || choice_rf0 || choice_rf1 || choice_rf2
{-87} __CPROVER_threads_exited#3 == __CPROVER_threads_exited#1 || !choice_rf3
{-88} __CPROVER_threads_exited#3 == __CPROVER_threads_exited#5 || !choice_rf4
{-89} !(__CPROVER_threads_exited#5$wclk$8 >= __CPROVER_threads_exited#3$rclk$8) || !choice_rf4
{-90} __CPROVER_threads_exited#3 == __CPROVER_threads_exited#7 || !choice_rf5
{-91} !(__CPROVER_threads_exited#7$wclk$8 >= __CPROVER_threads_exited#3$rclk$8) || !choice_rf5
{-92} (\guard#1 || (!__CPROVER_threads_exited#2[(long int)(unsigned long int)thread!0@1#2] || \guard#2) && !\guard#2) && !\guard#1 || \guard#3 || choice_rf3 || choice_rf4 || choice_rf5
{-93} __CPROVER_threads_exited#4 == __CPROVER_threads_exited#1 || !choice_rf6
{-94} !(__CPROVER_threads_exited#1$wclk$8 >= __CPROVER_threads_exited#4$rclk$8) || !choice_rf6
{-95} __CPROVER_threads_exited#4 == __CPROVER_threads_exited#7 || !choice_rf7
{-96} !(__CPROVER_threads_exited#7$wclk$8 >= __CPROVER_threads_exited#4$rclk$8) || !choice_rf7
{-97} choice_rf6 || choice_rf7
{-98} __CPROVER_threads_exited#6 == __CPROVER_threads_exited#1 || !choice_rf8
{-99} !(__CPROVER_threads_exited#1$wclk$8 >= __CPROVER_threads_exited#6$rclk$8) || !choice_rf8
{-100} __CPROVER_threads_exited#6 == __CPROVER_threads_exited#5 || !choice_rf9
{-101} !(__CPROVER_threads_exited#5$wclk$8 >= __CPROVER_threads_exited#6$rclk$8) || !choice_rf9
{-102} choice_rf8 || choice_rf9
{-103} __CPROVER_next_thread_id#3 == __CPROVER_next_thread_id#1 || !choice_rf10
{-104} __CPROVER_next_thread_id#3 == __CPROVER_next_thread_id#2 || !choice_rf11
{-105} choice_rf10 || choice_rf11
{-106} __CPROVER_next_thread_id#6 == __CPROVER_next_thread_id#1 || !choice_rf12
{-107} __CPROVER_next_thread_id#6 == __CPROVER_next_thread_id#2 || !choice_rf13
{-108} __CPROVER_next_thread_id#6 == __CPROVER_next_thread_id#5 || !choice_rf14
{-109} choice_rf12 || choice_rf13 || choice_rf14
{-110} __CPROVER_next_thread_id#7 == __CPROVER_next_thread_id#1 || !choice_rf15
{-111} __CPROVER_next_thread_id#7 == __CPROVER_next_thread_id#2 || !choice_rf16
{-112} __CPROVER_next_thread_id#7 == __CPROVER_next_thread_id#5 || !choice_rf17
{-113} (\guard#1 || (!__CPROVER_threads_exited#2[(long int)(unsigned long int)thread!0@1#2] || \guard#2) && !\guard#2) && !\guard#1 || choice_rf15 || choice_rf16 || choice_rf17
{-114} x#3 == x#1 || !choice_rf18
{-115} !(x#1$wclk$8 >= x#3$rclk$8) || !choice_rf18
{-116} x#3 == x#2 || !choice_rf19
{-117} !(x#2$wclk$8 >= x#3$rclk$8) || !choice_rf19
{-118} choice_rf18 || choice_rf19
{-119} y#4 == y#1 || !choice_rf20
{-120} !(y#1$wclk$8 >= y#4$rclk$8) || !choice_rf20
{-121} y#4 == y#2 || !choice_rf21
{-122} !(y#2$wclk$8 >= y#4$rclk$8) || !choice_rf21
{-123} y#4 == y#3 || !choice_rf22
{-124} !(y#3$wclk$8 >= y#4$rclk$8) || !choice_rf22
{-125} choice_rf20 || choice_rf21 || choice_rf22
{-126} y#5 == y#1 || !choice_rf23
{-127} !(y#1$wclk$8 >= y#5$rclk$8) || !choice_rf23
{-128} y#5 == y#2 || !choice_rf24
{-129} !(y#2$wclk$8 >= y#5$rclk$8) || !choice_rf24
{-130} y#5 == y#3 || !choice_rf25
{-131} !(y#3$wclk$8 >= y#5$rclk$8) || !choice_rf25
{-132} choice_rf23 || choice_rf24 || choice_rf25
{-133} !(__CPROVER_threads_exited#1$wclk$8 >= __CPROVER_threads_exited#5$wclk$8) || !choice_ws-ext26
{-134} !(__CPROVER_threads_exited#5$wclk$8 >= __CPROVER_threads_exited#1$wclk$8) || choice_ws-ext26
{-135} !(__CPROVER_threads_exited#1$wclk$8 >= __CPROVER_threads_exited#7$wclk$8) || !choice_ws-ext27
{-136} !(__CPROVER_threads_exited#7$wclk$8 >= __CPROVER_threads_exited#1$wclk$8) || choice_ws-ext27
{-137} !(__CPROVER_threads_exited#5$wclk$8 >= __CPROVER_threads_exited#7$wclk$8) || !choice_ws-ext28
{-138} !(__CPROVER_threads_exited#7$wclk$8 >= __CPROVER_threads_exited#5$wclk$8) || choice_ws-ext28
{-139} !(x#1$wclk$8 >= x#2$wclk$8) || !choice_ws-ext29
{-140} !(x#2$wclk$8 >= x#1$wclk$8) || choice_ws-ext29
{-141} !(y#1$wclk$8 >= y#2$wclk$8) || !choice_ws-ext30
{-142} !(y#2$wclk$8 >= y#1$wclk$8) || choice_ws-ext30
{-143} !(y#1$wclk$8 >= y#3$wclk$8) || !choice_ws-ext31
{-144} !(y#3$wclk$8 >= y#1$wclk$8) || choice_ws-ext31
{-145} !(t1$12$spwnclk$8 >= va_arg0$wclk$8)
{-146} !(t1$15$spwnclk$8 >= va_arg0$wclk$8)
{-147} !(__CPROVER_pipe_count#1$wclk$8 >= y#1$wclk$8)
{-148} !(y#1$wclk$8 >= x#1$wclk$8)
{-149} !(x#1$wclk$8 >= __CPROVER_threads_exited#1$wclk$8)
{-150} !(__CPROVER_threads_exited#1$wclk$8 >= __CPROVER_next_thread_id#1$wclk$8)
{-151} !(__CPROVER_next_thread_id#1$wclk$8 >= __CPROVER_deallocated#1$wclk$8)
{-152} !(__CPROVER_deallocated#1$wclk$8 >= __CPROVER_dead_object#1$wclk$8)
{-153} !(__CPROVER_dead_object#1$wclk$8 >= __CPROVER_malloc_object#1$wclk$8)
{-154} !(__CPROVER_malloc_object#1$wclk$8 >= __CPROVER_malloc_size#1$wclk$8)
{-155} !(__CPROVER_malloc_size#1$wclk$8 >= __CPROVER_malloc_is_new_array#1$wclk$8)
{-156} !(__CPROVER_malloc_is_new_array#1$wclk$8 >= __CPROVER_memory_leak#1$wclk$8)
{-157} !(__CPROVER_memory_leak#1$wclk$8 >= __CPROVER_next_thread_id#2$wclk$8)
{-158} !(__CPROVER_next_thread_id#2$wclk$8 >= t1$12$spwnclk$8)
{-159} !(t1$12$spwnclk$8 >= __CPROVER_next_thread_id#3$rclk$8)
{-160} __CPROVER_next_thread_id#3$rclk$8 == __CPROVER_next_thread_id#5$wclk$8
{-161} !(__CPROVER_next_thread_id#5$wclk$8 >= t1$15$spwnclk$8)
{-162} !(t1$15$spwnclk$8 >= __CPROVER_next_thread_id#6$rclk$8)
{-163} !(__CPROVER_next_thread_id#6$rclk$8 >= __CPROVER_threads_exited#2$rclk$8)
{-164} !(__CPROVER_threads_exited#2$rclk$8 >= __CPROVER_next_thread_id#7$rclk$8)
{-165} !(__CPROVER_next_thread_id#7$rclk$8 >= __CPROVER_threads_exited#3$rclk$8)
{-166} !(va_arg0$wclk$8 >= va_arg0#1$wclk$8)
{-167} !(va_arg0#1$wclk$8 >= y#2$wclk$8)
{-168} !(y#2$wclk$8 >= y#3$wclk$8)
{-169} !(y#3$wclk$8 >= x#2$wclk$8)
{-170} !(x#2$wclk$8 >= __CPROVER_threads_exited#4$rclk$8)
{-171} !(__CPROVER_threads_exited#4$rclk$8 >= __CPROVER_threads_exited#5$wclk$8)
{-172} !(va_arg0$wclk$8 >= va_arg0#1$wclk$8)
{-173} !(va_arg0#1$wclk$8 >= y#4$rclk$8)
{-174} !(y#4$rclk$8 >= x#3$rclk$8)
{-175} !(x#3$rclk$8 >= y#5$rclk$8)
{-176} !(y#5$rclk$8 >= __CPROVER_threads_exited#6$rclk$8)
{-177} !(__CPROVER_threads_exited#6$rclk$8 >= __CPROVER_threads_exited#7$wclk$8)
{-178} __CPROVER_threads_exited#1$wclk$8 >= __CPROVER_threads_exited#5$wclk$8 || !(__CPROVER_threads_exited#2$rclk$8 >= __CPROVER_threads_exited#5$wclk$8) || !choice_rf0 || \guard#1 || \guard#2
{-179} __CPROVER_threads_exited#5$wclk$8 >= __CPROVER_threads_exited#1$wclk$8 || !(__CPROVER_threads_exited#2$rclk$8 >= __CPROVER_threads_exited#1$wclk$8) || !choice_rf1 || \guard#1 || \guard#2
{-180} __CPROVER_threads_exited#1$wclk$8 >= __CPROVER_threads_exited#5$wclk$8 || (\guard#1 || (!__CPROVER_threads_exited#2[(long int)(unsigned long int)thread!0@1#2] || \guard#2) && !\guard#2) && !\guard#1 || !(__CPROVER_threads_exited#3$rclk$8 >= __CPROVER_threads_exited#5$wclk$8) || !choice_rf3 || \guard#3
{-181} __CPROVER_threads_exited#5$wclk$8 >= __CPROVER_threads_exited#1$wclk$8 || (\guard#1 || (!__CPROVER_threads_exited#2[(long int)(unsigned long int)thread!0@1#2] || \guard#2) && !\guard#2) && !\guard#1 || !(__CPROVER_threads_exited#3$rclk$8 >= __CPROVER_threads_exited#1$wclk$8) || !choice_rf4 || \guard#3
{-182} __CPROVER_threads_exited#1$wclk$8 >= __CPROVER_threads_exited#5$wclk$8 || !(__CPROVER_threads_exited#4$rclk$8 >= __CPROVER_threads_exited#5$wclk$8) || !choice_rf6
{-183} __CPROVER_threads_exited#1$wclk$8 >= __CPROVER_threads_exited#5$wclk$8 || !(__CPROVER_threads_exited#6$rclk$8 >= __CPROVER_threads_exited#5$wclk$8) || !choice_rf8
{-184} __CPROVER_threads_exited#5$wclk$8 >= __CPROVER_threads_exited#1$wclk$8 || !(__CPROVER_threads_exited#6$rclk$8 >= __CPROVER_threads_exited#1$wclk$8) || !choice_rf9
{-185} __CPROVER_threads_exited#1$wclk$8 >= __CPROVER_threads_exited#7$wclk$8 || !(__CPROVER_threads_exited#2$rclk$8 >= __CPROVER_threads_exited#7$wclk$8) || !choice_rf0 || \guard#1 || \guard#2
{-186} __CPROVER_threads_exited#7$wclk$8 >= __CPROVER_threads_exited#1$wclk$8 || !(__CPROVER_threads_exited#2$rclk$8 >= __CPROVER_threads_exited#1$wclk$8) || !choice_rf2 || \guard#1 || \guard#2
{-187} __CPROVER_threads_exited#1$wclk$8 >= __CPROVER_threads_exited#7$wclk$8 || (\guard#1 || (!__CPROVER_threads_exited#2[(long int)(unsigned long int)thread!0@1#2] || \guard#2) && !\guard#2) && !\guard#1 || !(__CPROVER_threads_exited#3$rclk$8 >= __CPROVER_threads_exited#7$wclk$8) || !choice_rf3 || \guard#3
{-188} __CPROVER_threads_exited#7$wclk$8 >= __CPROVER_threads_exited#1$wclk$8 || (\guard#1 || (!__CPROVER_threads_exited#2[(long int)(unsigned long int)thread!0@1#2] || \guard#2) && !\guard#2) && !\guard#1 || !(__CPROVER_threads_exited#3$rclk$8 >= __CPROVER_threads_exited#1$wclk$8) || !choice_rf5 || \guard#3
{-189} __CPROVER_threads_exited#1$wclk$8 >= __CPROVER_threads_exited#7$wclk$8 || !(__CPROVER_threads_exited#4$rclk$8 >= __CPROVER_threads_exited#7$wclk$8) || !choice_rf6
{-190} __CPROVER_threads_exited#7$wclk$8 >= __CPROVER_threads_exited#1$wclk$8 || !(__CPROVER_threads_exited#4$rclk$8 >= __CPROVER_threads_exited#1$wclk$8) || !choice_rf7
{-191} __CPROVER_threads_exited#1$wclk$8 >= __CPROVER_threads_exited#7$wclk$8 || !(__CPROVER_threads_exited#6$rclk$8 >= __CPROVER_threads_exited#7$wclk$8) || !choice_rf8
{-192} __CPROVER_threads_exited#5$wclk$8 >= __CPROVER_threads_exited#7$wclk$8 || !(__CPROVER_threads_exited#2$rclk$8 >= __CPROVER_threads_exited#7$wclk$8) || !choice_rf1 || \guard#1 || \guard#2
{-193} __CPROVER_threads_exited#7$wclk$8 >= __CPROVER_threads_exited#5$wclk$8 || !(__CPROVER_threads_exited#2$rclk$8 >= __CPROVER_threads_exited#5$wclk$8) || !choice_rf2 || \guard#1 || \guard#2
{-194} __CPROVER_threads_exited#5$wclk$8 >= __CPROVER_threads_exited#7$wclk$8 || (\guard#1 || (!__CPROVER_threads_exited#2[(long int)(unsigned long int)thread!0@1#2] || \guard#2) && !\guard#2) && !\guard#1 || !(__CPROVER_threads_exited#3$rclk$8 >= __CPROVER_threads_exited#7$wclk$8) || !choice_rf4 || \guard#3
{-195} __CPROVER_threads_exited#7$wclk$8 >= __CPROVER_threads_exited#5$wclk$8 || (\guard#1 || (!__CPROVER_threads_exited#2[(long int)(unsigned long int)thread!0@1#2] || \guard#2) && !\guard#2) && !\guard#1 || !(__CPROVER_threads_exited#3$rclk$8 >= __CPROVER_threads_exited#5$wclk$8) || !choice_rf5 || \guard#3
{-196} __CPROVER_threads_exited#7$wclk$8 >= __CPROVER_threads_exited#5$wclk$8 || !(__CPROVER_threads_exited#4$rclk$8 >= __CPROVER_threads_exited#5$wclk$8) || !choice_rf7
{-197} __CPROVER_threads_exited#5$wclk$8 >= __CPROVER_threads_exited#7$wclk$8 || !(__CPROVER_threads_exited#6$rclk$8 >= __CPROVER_threads_exited#7$wclk$8) || !choice_rf9
{-198} !(__CPROVER_next_thread_id#3$rclk$8 >= __CPROVER_next_thread_id#2$wclk$8) || !choice_rf10
{-199} !(__CPROVER_next_thread_id#6$rclk$8 >= __CPROVER_next_thread_id#2$wclk$8) || !choice_rf12
{-200} (\guard#1 || (!__CPROVER_threads_exited#2[(long int)(unsigned long int)thread!0@1#2] || \guard#2) && !\guard#2) && !\guard#1 || !(__CPROVER_next_thread_id#7$rclk$8 >= __CPROVER_next_thread_id#2$wclk$8) || !choice_rf15
{-201} __CPROVER_next_thread_id#3$rclk$8 == __CPROVER_next_thread_id#5$wclk$8 || !choice_rf10
{-202} !(__CPROVER_next_thread_id#6$rclk$8 >= __CPROVER_next_thread_id#5$wclk$8) || !choice_rf12
{-203} (\guard#1 || (!__CPROVER_threads_exited#2[(long int)(unsigned long int)thread!0@1#2] || \guard#2) && !\guard#2) && !\guard#1 || !(__CPROVER_next_thread_id#7$rclk$8 >= __CPROVER_next_thread_id#5$wclk$8) || !choice_rf15
{-204} __CPROVER_next_thread_id#3$rclk$8 == __CPROVER_next_thread_id#5$wclk$8 || !choice_rf11
{-205} !(__CPROVER_next_thread_id#6$rclk$8 >= __CPROVER_next_thread_id#5$wclk$8) || !choice_rf13
{-206} (\guard#1 || (!__CPROVER_threads_exited#2[(long int)(unsigned long int)thread!0@1#2] || \guard#2) && !\guard#2) && !\guard#1 || !(__CPROVER_next_thread_id#7$rclk$8 >= __CPROVER_next_thread_id#5$wclk$8) || !choice_rf16
{-207} x#1$wclk$8 >= x#2$wclk$8 || !(x#3$rclk$8 >= x#2$wclk$8) || !choice_rf18
{-208} x#2$wclk$8 >= x#1$wclk$8 || !(x#3$rclk$8 >= x#1$wclk$8) || !choice_rf19
{-209} y#1$wclk$8 >= y#2$wclk$8 || !(y#4$rclk$8 >= y#2$wclk$8) || !choice_rf20
{-210} y#2$wclk$8 >= y#1$wclk$8 || !(y#4$rclk$8 >= y#1$wclk$8) || !choice_rf21
{-211} y#1$wclk$8 >= y#2$wclk$8 || !(y#5$rclk$8 >= y#2$wclk$8) || !choice_rf23
{-212} y#2$wclk$8 >= y#1$wclk$8 || !(y#5$rclk$8 >= y#1$wclk$8) || !choice_rf24
{-213} y#3$wclk$8 >= y#1$wclk$8 || !(y#4$rclk$8 >= y#1$wclk$8) || !choice_rf22
{-214} y#1$wclk$8 >= y#3$wclk$8 || !(y#4$rclk$8 >= y#3$wclk$8) || !choice_rf20
{-215} y#3$wclk$8 >= y#1$wclk$8 || !(y#5$rclk$8 >= y#1$wclk$8) || !choice_rf25
{-216} y#1$wclk$8 >= y#3$wclk$8 || !(y#5$rclk$8 >= y#3$wclk$8) || !choice_rf23
{-217} !(y#4$rclk$8 >= y#3$wclk$8) || !choice_rf21
{-218} !(y#5$rclk$8 >= y#3$wclk$8) || !choice_rf24
|--------------------------
{1} xt!2@1#2 == yt!2@1#3

