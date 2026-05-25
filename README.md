# ft_printf
Grade achieved: 122% ✅
>[!WARNING]
>One test did not pass for the precision flag

## ℹ️Description
- A thin library which reproduces the behaviour of printf() from <stdio.h>
- No external library functions allowed, except for va_args and write()
  
### Mandatory Section:
- Handles the following conversions: %c, %p, %u, %d, %i, %x, %X, %%

### 🏆 Bonus Section:
- Handles the following flags: '-', '0', '.', ' ', '#', '+'

## 🛠️ Usage

### As an Included Library in a Makefile:
```Makefile
# In your Makefile
FT_PRINTF := <path_to_ft_printf>/libftprintf.a

$(NAME): $(OBJECT_FILES) $(FT_PRINTF)
		$(CC) $(CFLAGS) $^ -o $(NAME)

$(FT_PRINTF):
	@make -C <path_to_ft_printf>
```
```C
//In your C file:
#include "ft_printf.h"
```

## 👥 Author
Matilda Tice (Github: mstice, 42: mtice)  
