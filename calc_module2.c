// Kernel basic / Export symbols / module 2
// - Create three modules who all depend on one another.
// - First module takes two module parameters of type int.
// - Second module uses these parameters to add and substract 
//   them from one another.
// - Third module prints out the results
// - You need to export symbols as functions in the first and 
//   second module. First will have typical getters (get a and get b) 
//   and the second will have the add and substract

#include <linux/kernel.h>
#include <linux/module.h>

int my_calc_export(int a, int b, int op); 

int my_calc_export(int a, int b, int op)
{
    int c = 0; 
    
    switch(op)
	{
	case 1:	    
	    c = a + b; 
	    printk("\n QIU: Addition: %d + %d = %d\n", 
		   a, b, c);
	    break;

	case 2:
	    c = a - b; 
	    printk("\n QIU: Subtraction: %d - %d = %d \n",
		   a, b, c);
	    break;

	case 3:
	    c = a * b; 
	    printk("\n QIU: Multiplication: %d * %d = %d \n",
		   a, b, c);
	    break;

	case 4:
	    c = a / b; 
	    printk("\n QIU: Division: %d / %d = %d\n", 
		   a, b, c );
         break;

	default:
	    printk("\n QIU: Unknown Operation for calculation... \n");
	    break; 
  }
    return c; 
}

static int __init calc_init(void)
{
    printk("\n QIU: Module 2 Loaded...... \n");
    return 0;
}

static void __exit calc_exit(void)
{
    printk(KERN_ALERT "\n QIU: Module 2 removed \n");

}

MODULE_LICENSE("GPL");
module_init(calc_init);
module_exit(calc_exit);
EXPORT_SYMBOL_GPL(my_calc_export);

