/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf_define.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ztrouill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/23 12:36:48 by ztrouill     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 19:01:49 by ztrouill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_DEFINE_H
# define FDF_DEFINE_H
/*
 *** DEFINE WINDOW SIZE ***
*/

# define WIDTH		1280
# define HEIGHT		720

/*
 *** DEFINE KEY EVENTS ***
*/

# define KEY_H		4
# define KEY_C		8
# define KEY_V		9
# define KEY_ESC	53
# define KEY_MINUS	78
# define KEY_PLUS	69
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_SPACE	49

/*
 *** DEFINE COLORS***
*/

# define PINK		0xD2B4DE
# define CYAN		0xffff
# define BLUE		0x0000FF
# define MAGENTA	0xFF00FF
# define GOOSE_POOH	0x54442B
# define ROYAL_BLUE	0x1418E5
# define INDIGO		0x0d0f96
# define WHITE		0xffffff
# define BROWN_SUGAR 0xE8985E

/*
 *** DEFINE USAGE ***
*/

# define USAGE_MAIN "usage: ./fdf source_file.fdf music.wav && enjoy"
# define ERROR "ERROR // not a valid file :("
# define TOO_BIG "This map is too big... Sorry bro i'm not able to do this :/"

/*
 *** DEFINE TOOL_BAR ***
*/

# define ICONE_UP_1 "^"
# define ICONE_UP_2 "|"
# define ICONE_LR "<--> :"
# define ICONE_DOWN "v"
# define TEXT_1 "    C H A N G E  V I E W            Q U I T          "
# define TEXT_2 "H I D E  T O O L  B A R            M O V E          "
# define TEXT_3 "                            Z O O M +          Z O O M -           D I S C O  M O D E"
# define ICONE_1 "V :                           ESC :              H :        "
# define ICONE_2 "                        + :                - :                SP : "
# define OR_1 "                          ||                 ||                 "
# define OR_2 "||                 "//||                 ||                 ||"
# define OR_3	 "                                         ||                 ||"
#endif
