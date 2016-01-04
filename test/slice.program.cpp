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
size of program expression: 298 steps
no slicing due to threads
Generated 1 VCC(s), 1 remaining after simplification

VERIFICATION CONDITIONS:

file slice.c line 13 function p3
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
{-71} p2#return_value!1#2 == nondet_symbol(symex::nondet1)
{-72} __CPROVER_threads_exited#5 == __CPROVER_threads_exited#4 WITH [1:=TRUE]
{-73} __CPROVER_thread_id!2#2 == id!2@0#1
{-74} va_arg0#1 == NULL
{-75} xt!2@1#2 == x#2
{-76} yt!2@1#2 == y#4
{-77} p3#return_value!2#2 == nondet_symbol(symex::nondet2)
{-78} __CPROVER_threads_exited#7 == __CPROVER_threads_exited#6 WITH [(long int)id!2@0#1:=TRUE]
{-79} __CPROVER_threads_exited#2 == __CPROVER_threads_exited#1 || !choice_rf0
{-80} __CPROVER_threads_exited#2 == __CPROVER_threads_exited#5 || !choice_rf1
{-81} !(__CPROVER_threads_exited#5$wclk$8 >= __CPROVER_threads_exited#2$rclk$8) || !choice_rf1
{-82} __CPROVER_threads_exited#2 == __CPROVER_threads_exited#7 || !choice_rf2
{-83} !(__CPROVER_threads_exited#7$wclk$8 >= __CPROVER_threads_exited#2$rclk$8) || !choice_rf2
{-84} \guard#1 || \guard#2 || choice_rf0 || choice_rf1 || choice_rf2
{-85} __CPROVER_threads_exited#3 == __CPROVER_threads_exited#1 || !choice_rf3
{-86} __CPROVER_threads_exited#3 == __CPROVER_threads_exited#5 || !choice_rf4
{-87} !(__CPROVER_threads_exited#5$wclk$8 >= __CPROVER_threads_exited#3$rclk$8) || !choice_rf4
{-88} __CPROVER_threads_exited#3 == __CPROVER_threads_exited#7 || !choice_rf5
{-89} !(__CPROVER_threads_exited#7$wclk$8 >= __CPROVER_threads_exited#3$rclk$8) || !choice_rf5
{-90} (\guard#1 || (!__CPROVER_threads_exited#2[(long int)(unsigned long int)thread!0@1#2] || \guard#2) && !\guard#2) && !\guard#1 || \guard#3 || choice_rf3 || choice_rf4 || choice_rf5
{-91} __CPROVER_threads_exited#4 == __CPROVER_threads_exited#1 || !choice_rf6
{-92} !(__CPROVER_threads_exited#1$wclk$8 >= __CPROVER_threads_exited#4$rclk$8) || !choice_rf6
{-93} __CPROVER_threads_exited#4 == __CPROVER_threads_exited#7 || !choice_rf7
{-94} !(__CPROVER_threads_exited#7$wclk$8 >= __CPROVER_threads_exited#4$rclk$8) || !choice_rf7
{-95} choice_rf6 || choice_rf7
{-96} __CPROVER_threads_exited#6 == __CPROVER_threads_exited#1 || !choice_rf8
{-97} !(__CPROVER_threads_exited#1$wclk$8 >= __CPROVER_threads_exited#6$rclk$8) || !choice_rf8
{-98} __CPROVER_threads_exited#6 == __CPROVER_threads_exited#5 || !choice_rf9
{-99} !(__CPROVER_threads_exited#5$wclk$8 >= __CPROVER_threads_exited#6$rclk$8) || !choice_rf9
{-100} choice_rf8 || choice_rf9
{-101} __CPROVER_next_thread_id#3 == __CPROVER_next_thread_id#1 || !choice_rf10
{-102} __CPROVER_next_thread_id#3 == __CPROVER_next_thread_id#2 || !choice_rf11
{-103} choice_rf10 || choice_rf11
{-104} __CPROVER_next_thread_id#6 == __CPROVER_next_thread_id#1 || !choice_rf12
{-105} __CPROVER_next_thread_id#6 == __CPROVER_next_thread_id#2 || !choice_rf13
{-106} __CPROVER_next_thread_id#6 == __CPROVER_next_thread_id#5 || !choice_rf14
{-107} choice_rf12 || choice_rf13 || choice_rf14
{-108} __CPROVER_next_thread_id#7 == __CPROVER_next_thread_id#1 || !choice_rf15
{-109} __CPROVER_next_thread_id#7 == __CPROVER_next_thread_id#2 || !choice_rf16
{-110} __CPROVER_next_thread_id#7 == __CPROVER_next_thread_id#5 || !choice_rf17
{-111} (\guard#1 || (!__CPROVER_threads_exited#2[(long int)(unsigned long int)thread!0@1#2] || \guard#2) && !\guard#2) && !\guard#1 || choice_rf15 || choice_rf16 || choice_rf17
{-112} x#2 == x#1 || !choice_rf18
{-113} !(x#1$wclk$8 >= x#2$rclk$8) || !choice_rf18
{-114} choice_rf18
{-115} y#4 == y#1 || !choice_rf19
{-116} !(y#1$wclk$8 >= y#4$rclk$8) || !choice_rf19
{-117} y#4 == y#2 || !choice_rf20
{-118} !(y#2$wclk$8 >= y#4$rclk$8) || !choice_rf20
{-119} y#4 == y#3 || !choice_rf21
{-120} !(y#3$wclk$8 >= y#4$rclk$8) || !choice_rf21
{-121} choice_rf19 || choice_rf20 || choice_rf21
{-122} !(__CPROVER_threads_exited#1$wclk$8 >= __CPROVER_threads_exited#5$wclk$8) || !choice_ws-ext22
{-123} !(__CPROVER_threads_exited#5$wclk$8 >= __CPROVER_threads_exited#1$wclk$8) || choice_ws-ext22
{-124} !(__CPROVER_threads_exited#1$wclk$8 >= __CPROVER_threads_exited#7$wclk$8) || !choice_ws-ext23
{-125} !(__CPROVER_threads_exited#7$wclk$8 >= __CPROVER_threads_exited#1$wclk$8) || choice_ws-ext23
{-126} !(__CPROVER_threads_exited#5$wclk$8 >= __CPROVER_threads_exited#7$wclk$8) || !choice_ws-ext24
{-127} !(__CPROVER_threads_exited#7$wclk$8 >= __CPROVER_threads_exited#5$wclk$8) || choice_ws-ext24
{-128} !(y#1$wclk$8 >= y#2$wclk$8) || !choice_ws-ext25
{-129} !(y#2$wclk$8 >= y#1$wclk$8) || choice_ws-ext25
{-130} !(y#1$wclk$8 >= y#3$wclk$8) || !choice_ws-ext26
{-131} !(y#3$wclk$8 >= y#1$wclk$8) || choice_ws-ext26
{-132} !(t1$12$spwnclk$8 >= va_arg0$wclk$8)
{-133} !(t1$15$spwnclk$8 >= va_arg0$wclk$8)
{-134} !(__CPROVER_pipe_count#1$wclk$8 >= y#1$wclk$8)
{-135} !(y#1$wclk$8 >= x#1$wclk$8)
{-136} !(x#1$wclk$8 >= __CPROVER_threads_exited#1$wclk$8)
{-137} !(__CPROVER_threads_exited#1$wclk$8 >= __CPROVER_next_thread_id#1$wclk$8)
{-138} !(__CPROVER_next_thread_id#1$wclk$8 >= __CPROVER_deallocated#1$wclk$8)
{-139} !(__CPROVER_deallocated#1$wclk$8 >= __CPROVER_dead_object#1$wclk$8)
{-140} !(__CPROVER_dead_object#1$wclk$8 >= __CPROVER_malloc_object#1$wclk$8)
{-141} !(__CPROVER_malloc_object#1$wclk$8 >= __CPROVER_malloc_size#1$wclk$8)
{-142} !(__CPROVER_malloc_size#1$wclk$8 >= __CPROVER_malloc_is_new_array#1$wclk$8)
{-143} !(__CPROVER_malloc_is_new_array#1$wclk$8 >= __CPROVER_memory_leak#1$wclk$8)
{-144} !(__CPROVER_memory_leak#1$wclk$8 >= __CPROVER_next_thread_id#2$wclk$8)
{-145} !(__CPROVER_next_thread_id#2$wclk$8 >= t1$12$spwnclk$8)
{-146} !(t1$12$spwnclk$8 >= __CPROVER_next_thread_id#3$rclk$8)
{-147} __CPROVER_next_thread_id#3$rclk$8 == __CPROVER_next_thread_id#5$wclk$8
{-148} !(__CPROVER_next_thread_id#5$wclk$8 >= t1$15$spwnclk$8)
{-149} !(t1$15$spwnclk$8 >= __CPROVER_next_thread_id#6$rclk$8)
{-150} !(__CPROVER_next_thread_id#6$rclk$8 >= __CPROVER_threads_exited#2$rclk$8)
{-151} !(__CPROVER_threads_exited#2$rclk$8 >= __CPROVER_next_thread_id#7$rclk$8)
{-152} !(__CPROVER_next_thread_id#7$rclk$8 >= __CPROVER_threads_exited#3$rclk$8)
{-153} !(va_arg0$wclk$8 >= va_arg0#1$wclk$8)
{-154} !(va_arg0#1$wclk$8 >= y#2$wclk$8)
{-155} !(y#2$wclk$8 >= y#3$wclk$8)
{-156} !(y#3$wclk$8 >= __CPROVER_threads_exited#4$rclk$8)
{-157} !(__CPROVER_threads_exited#4$rclk$8 >= __CPROVER_threads_exited#5$wclk$8)
{-158} !(va_arg0$wclk$8 >= va_arg0#1$wclk$8)
{-159} !(va_arg0#1$wclk$8 >= x#2$rclk$8)
{-160} !(x#2$rclk$8 >= y#4$rclk$8)
{-161} !(y#4$rclk$8 >= __CPROVER_threads_exited#6$rclk$8)
{-162} !(__CPROVER_threads_exited#6$rclk$8 >= __CPROVER_threads_exited#7$wclk$8)
{-163} __CPROVER_threads_exited#1$wclk$8 >= __CPROVER_threads_exited#5$wclk$8 || !(__CPROVER_threads_exited#2$rclk$8 >= __CPROVER_threads_exited#5$wclk$8) || !choice_rf0 || \guard#1 || \guard#2
{-164} __CPROVER_threads_exited#5$wclk$8 >= __CPROVER_threads_exited#1$wclk$8 || !(__CPROVER_threads_exited#2$rclk$8 >= __CPROVER_threads_exited#1$wclk$8) || !choice_rf1 || \guard#1 || \guard#2
{-165} __CPROVER_threads_exited#1$wclk$8 >= __CPROVER_threads_exited#5$wclk$8 || (\guard#1 || (!__CPROVER_threads_exited#2[(long int)(unsigned long int)thread!0@1#2] || \guard#2) && !\guard#2) && !\guard#1 || !(__CPROVER_threads_exited#3$rclk$8 >= __CPROVER_threads_exited#5$wclk$8) || !choice_rf3 || \guard#3
{-166} __CPROVER_threads_exited#5$wclk$8 >= __CPROVER_threads_exited#1$wclk$8 || (\guard#1 || (!__CPROVER_threads_exited#2[(long int)(unsigned long int)thread!0@1#2] || \guard#2) && !\guard#2) && !\guard#1 || !(__CPROVER_threads_exited#3$rclk$8 >= __CPROVER_threads_exited#1$wclk$8) || !choice_rf4 || \guard#3
{-167} __CPROVER_threads_exited#1$wclk$8 >= __CPROVER_threads_exited#5$wclk$8 || !(__CPROVER_threads_exited#4$rclk$8 >= __CPROVER_threads_exited#5$wclk$8) || !choice_rf6
{-168} __CPROVER_threads_exited#1$wclk$8 >= __CPROVER_threads_exited#5$wclk$8 || !(__CPROVER_threads_exited#6$rclk$8 >= __CPROVER_threads_exited#5$wclk$8) || !choice_rf8
{-169} __CPROVER_threads_exited#5$wclk$8 >= __CPROVER_threads_exited#1$wclk$8 || !(__CPROVER_threads_exited#6$rclk$8 >= __CPROVER_threads_exited#1$wclk$8) || !choice_rf9
{-170} __CPROVER_threads_exited#1$wclk$8 >= __CPROVER_threads_exited#7$wclk$8 || !(__CPROVER_threads_exited#2$rclk$8 >= __CPROVER_threads_exited#7$wclk$8) || !choice_rf0 || \guard#1 || \guard#2
{-171} __CPROVER_threads_exited#7$wclk$8 >= __CPROVER_threads_exited#1$wclk$8 || !(__CPROVER_threads_exited#2$rclk$8 >= __CPROVER_threads_exited#1$wclk$8) || !choice_rf2 || \guard#1 || \guard#2
{-172} __CPROVER_threads_exited#1$wclk$8 >= __CPROVER_threads_exited#7$wclk$8 || (\guard#1 || (!__CPROVER_threads_exited#2[(long int)(unsigned long int)thread!0@1#2] || \guard#2) && !\guard#2) && !\guard#1 || !(__CPROVER_threads_exited#3$rclk$8 >= __CPROVER_threads_exited#7$wclk$8) || !choice_rf3 || \guard#3
{-173} __CPROVER_threads_exited#7$wclk$8 >= __CPROVER_threads_exited#1$wclk$8 || (\guard#1 || (!__CPROVER_threads_exited#2[(long int)(unsigned long int)thread!0@1#2] || \guard#2) && !\guard#2) && !\guard#1 || !(__CPROVER_threads_exited#3$rclk$8 >= __CPROVER_threads_exited#1$wclk$8) || !choice_rf5 || \guard#3
{-174} __CPROVER_threads_exited#1$wclk$8 >= __CPROVER_threads_exited#7$wclk$8 || !(__CPROVER_threads_exited#4$rclk$8 >= __CPROVER_threads_exited#7$wclk$8) || !choice_rf6
{-175} __CPROVER_threads_exited#7$wclk$8 >= __CPROVER_threads_exited#1$wclk$8 || !(__CPROVER_threads_exited#4$rclk$8 >= __CPROVER_threads_exited#1$wclk$8) || !choice_rf7
{-176} __CPROVER_threads_exited#1$wclk$8 >= __CPROVER_threads_exited#7$wclk$8 || !(__CPROVER_threads_exited#6$rclk$8 >= __CPROVER_threads_exited#7$wclk$8) || !choice_rf8
{-177} __CPROVER_threads_exited#7$wclk$8 >= __CPROVER_threads_exited#5$wclk$8 || !(__CPROVER_threads_exited#2$rclk$8 >= __CPROVER_threads_exited#5$wclk$8) || !choice_rf2 || \guard#1 || \guard#2
{-178} __CPROVER_threads_exited#5$wclk$8 >= __CPROVER_threads_exited#7$wclk$8 || !(__CPROVER_threads_exited#2$rclk$8 >= __CPROVER_threads_exited#7$wclk$8) || !choice_rf1 || \guard#1 || \guard#2
{-179} __CPROVER_threads_exited#7$wclk$8 >= __CPROVER_threads_exited#5$wclk$8 || (\guard#1 || (!__CPROVER_threads_exited#2[(long int)(unsigned long int)thread!0@1#2] || \guard#2) && !\guard#2) && !\guard#1 || !(__CPROVER_threads_exited#3$rclk$8 >= __CPROVER_threads_exited#5$wclk$8) || !choice_rf5 || \guard#3
{-180} __CPROVER_threads_exited#5$wclk$8 >= __CPROVER_threads_exited#7$wclk$8 || (\guard#1 || (!__CPROVER_threads_exited#2[(long int)(unsigned long int)thread!0@1#2] || \guard#2) && !\guard#2) && !\guard#1 || !(__CPROVER_threads_exited#3$rclk$8 >= __CPROVER_threads_exited#7$wclk$8) || !choice_rf4 || \guard#3
{-181} __CPROVER_threads_exited#7$wclk$8 >= __CPROVER_threads_exited#5$wclk$8 || !(__CPROVER_threads_exited#4$rclk$8 >= __CPROVER_threads_exited#5$wclk$8) || !choice_rf7
{-182} __CPROVER_threads_exited#5$wclk$8 >= __CPROVER_threads_exited#7$wclk$8 || !(__CPROVER_threads_exited#6$rclk$8 >= __CPROVER_threads_exited#7$wclk$8) || !choice_rf9
{-183} (\guard#1 || (!__CPROVER_threads_exited#2[(long int)(unsigned long int)thread!0@1#2] || \guard#2) && !\guard#2) && !\guard#1 || !(__CPROVER_next_thread_id#7$rclk$8 >= __CPROVER_next_thread_id#2$wclk$8) || !choice_rf15
{-184} !(__CPROVER_next_thread_id#6$rclk$8 >= __CPROVER_next_thread_id#2$wclk$8) || !choice_rf12
{-185} !(__CPROVER_next_thread_id#3$rclk$8 >= __CPROVER_next_thread_id#2$wclk$8) || !choice_rf10
{-186} (\guard#1 || (!__CPROVER_threads_exited#2[(long int)(unsigned long int)thread!0@1#2] || \guard#2) && !\guard#2) && !\guard#1 || !(__CPROVER_next_thread_id#7$rclk$8 >= __CPROVER_next_thread_id#5$wclk$8) || !choice_rf15
{-187} !(__CPROVER_next_thread_id#6$rclk$8 >= __CPROVER_next_thread_id#5$wclk$8) || !choice_rf12
{-188} __CPROVER_next_thread_id#3$rclk$8 == __CPROVER_next_thread_id#5$wclk$8 || !choice_rf10
{-189} (\guard#1 || (!__CPROVER_threads_exited#2[(long int)(unsigned long int)thread!0@1#2] || \guard#2) && !\guard#2) && !\guard#1 || !(__CPROVER_next_thread_id#7$rclk$8 >= __CPROVER_next_thread_id#5$wclk$8) || !choice_rf16
{-190} !(__CPROVER_next_thread_id#6$rclk$8 >= __CPROVER_next_thread_id#5$wclk$8) || !choice_rf13
{-191} __CPROVER_next_thread_id#3$rclk$8 == __CPROVER_next_thread_id#5$wclk$8 || !choice_rf11
{-192} y#1$wclk$8 >= y#2$wclk$8 || !(y#4$rclk$8 >= y#2$wclk$8) || !choice_rf19
{-193} y#2$wclk$8 >= y#1$wclk$8 || !(y#4$rclk$8 >= y#1$wclk$8) || !choice_rf20
{-194} y#1$wclk$8 >= y#3$wclk$8 || !(y#4$rclk$8 >= y#3$wclk$8) || !choice_rf19
{-195} y#3$wclk$8 >= y#1$wclk$8 || !(y#4$rclk$8 >= y#1$wclk$8) || !choice_rf21
{-196} !(y#4$rclk$8 >= y#3$wclk$8) || !choice_rf20
|--------------------------
{1} xt!2@1#2 == yt!2@1#2

