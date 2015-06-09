// Kernel basic / Export symbols /module 1
// - Create three modules who all depend on one another.
// - First module takes two module parameters of type int.
// - Second module uses these parameters to add and substract 
//   them from one another.
// - Third module prints out the results
// - You need to export symbols as functions in the first and 
//   second module. First will have typical getters (get a and get b) 
//   and the second will have the add and substract


// 

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

int my_calc_export(int, int, int); 
int my_calc_print_export(int, int, int, int); 

int a = 0, b = 0, op = 0;
module_param(a, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
module_param(b, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
module_param(op, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);

static int __init calc_init(void)
{
  
    int c; 
    printk("\n QIU: Module 1 Loaded...... \n");

    if((a == 0) && (b == 0) && (op == 0))
	{     
	    printk("\n QIU: Supply Module Parameters...... \n");
	    printk("\n QIU: insmod <modulename>.ko op=<1-4> a=<int data> b=<int data> \n");
	    return 0;
	}
    printk("\n QIU: STDIO: a=%d; b=%d op=%d\n", 
	   a, b, op);

    c = my_calc_export( a, b, op); 
    // module 3 to printk out
    return 0; 
}

static void __exit calc_exit(void)
{
    printk(KERN_ALERT " QIU: Module 2 removed ");
}

MODULE_LICENSE("GPL");
module_init(calc_init);
module_exit(calc_exit)

