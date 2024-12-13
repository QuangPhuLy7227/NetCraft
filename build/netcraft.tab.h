/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     LAYER = 259,
     STRING = 260,
     STRING_LITERAL = 261,
     NUMBER = 262,
     LOAD_PROTOCOLS = 263,
     LIST_PROTOCOLS = 264,
     LIST_PROTOCOLS_BY_STACK = 265,
     STACK = 266,
     CRAFT_PACKET = 267,
     VIEW_PACKET = 268,
     MODIFY_PACKET = 269,
     SEND_PACKET = 270,
     PROTOCOL = 271,
     SRC_PORT = 272,
     DST_PORT = 273,
     PAYLOAD = 274
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define LAYER 259
#define STRING 260
#define STRING_LITERAL 261
#define NUMBER 262
#define LOAD_PROTOCOLS 263
#define LIST_PROTOCOLS 264
#define LIST_PROTOCOLS_BY_STACK 265
#define STACK 266
#define CRAFT_PACKET 267
#define VIEW_PACKET 268
#define MODIFY_PACKET 269
#define SEND_PACKET 270
#define PROTOCOL 271
#define SRC_PORT 272
#define DST_PORT 273
#define PAYLOAD 274




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 23 "src/parser/netcraft.y"
{
    char* string;
    int number;
}
/* Line 1529 of yacc.c.  */
#line 92 "/Users/quangphuly/Documents/NetCraft/build/netcraft.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

