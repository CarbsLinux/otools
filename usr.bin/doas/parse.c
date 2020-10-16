/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20200910

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 19 "usr.bin/doas/parse.y"
#include <sys/types.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <err.h>

#include "doas.h"

typedef struct {
	union {
		struct {
			int action;
			int options;
			const char *cmd;
			const char **cmdargs;
			const char **envlist;
		};
		const char **strlist;
		const char *str;
	};
	int lineno;
	int colno;
} yystype;
#define YYSTYPE yystype

FILE *yyfp;

struct rule **rules;
int nrules;
static int maxrules;

int parse_errors = 0;

static void yyerror(const char *, ...);
static int yylex(void);

static size_t
arraylen(const char **arr)
{
	size_t cnt = 0;

	while (*arr) {
		cnt++;
		arr++;
	}
	return cnt;
}

#line 74 "usr.bin/doas/parse.c"

#if ! defined(YYSTYPE) && ! defined(YYSTYPE_IS_DECLARED)
/* Default: YYSTYPE is the semantic value type. */
typedef int YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define TPERMIT 257
#define TDENY 258
#define TAS 259
#define TCMD 260
#define TARGS 261
#define TNOPASS 262
#define TPERSIST 263
#define TKEEPENV 264
#define TSETENV 265
#define TSTRING 266
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    1,    2,    2,    6,    6,    7,
    7,    7,    7,    8,    8,    3,    4,    4,    5,    5,
    9,    9,
};
static const YYINT yylen[] = {                            2,
    0,    2,    3,    2,    4,    2,    1,    0,    2,    1,
    1,    1,    4,    0,    2,    1,    0,    2,    0,    3,
    0,    2,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    4,    8,    7,    2,    0,    0,    0,    3,
   16,    0,   10,   11,   12,    0,    9,    0,    0,   14,
   18,    0,    5,    0,    0,   15,   13,   14,   20,    0,
};
static const YYINT yydgoto[] = {                          2,
    7,    8,   12,   19,   23,    9,   17,   24,   29,
};
static const YYINT yysindex[] = {                      -253,
   -1,   -6,    0,    0,    0,    0,    2, -256, -257,    0,
    0, -246,    0,    0,    0, -109,    0, -251, -244,    0,
    0, -249,    0, -123, -243,    0,    0,    0,    0, -247,
};
static const YYINT yyrindex[] = {                         1,
    0,    0,    0,    0,    0,    0,    0,    0, -245,    0,
    0,  -10,    0,    0,    0,    0,    0,    0,   10,    0,
    0,    0,    0,    0,   12,    0,    0,    0,    0,   13,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,   -4,    0,
};
#define YYTABLESIZE 259
static const YYINT yytable[] = {                         17,
    1,   27,    1,    6,   13,   14,   15,   16,    3,   11,
    1,   10,   18,   20,   21,   22,   25,   28,   26,   19,
    6,   21,   22,   30,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   26,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   17,
    4,    5,    0,    0,    0,    0,    0,    1,    1,
};
static const YYINT yycheck[] = {                         10,
    0,  125,  256,   10,  262,  263,  264,  265,   10,  266,
   10,   10,  259,  123,  266,  260,  266,  261,  266,   10,
  266,   10,   10,   28,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  266,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  260,
  257,  258,   -1,   -1,   -1,   -1,   -1,  257,  258,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 266
#define YYUNDFTOKEN 278
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"TPERMIT","TDENY",
"TAS","TCMD","TARGS","TNOPASS","TPERSIST","TKEEPENV","TSETENV","TSTRING",0,0,0,
0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : grammar",
"grammar :",
"grammar : grammar '\\n'",
"grammar : grammar rule '\\n'",
"grammar : error '\\n'",
"rule : action ident target cmd",
"action : TPERMIT options",
"action : TDENY",
"options :",
"options : options option",
"option : TNOPASS",
"option : TPERSIST",
"option : TKEEPENV",
"option : TSETENV '{' strlist '}'",
"strlist :",
"strlist : strlist TSTRING",
"ident : TSTRING",
"target :",
"target : TAS TSTRING",
"cmd :",
"cmd : TCMD TSTRING args",
"args :",
"args : TARGS strlist",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 189 "usr.bin/doas/parse.y"

void
yyerror(const char *fmt, ...)
{
	va_list va;

	fprintf(stderr, "doas: ");
	va_start(va, fmt);
	vfprintf(stderr, fmt, va);
	va_end(va);
	fprintf(stderr, " at line %d\n", yylval.lineno + 1);
	parse_errors++;
}

static struct keyword {
	const char *word;
	int token;
} keywords[] = {
	{ "deny", TDENY },
	{ "permit", TPERMIT },
	{ "as", TAS },
	{ "cmd", TCMD },
	{ "args", TARGS },
	{ "nopass", TNOPASS },
	{ "persist", TPERSIST },
	{ "keepenv", TKEEPENV },
	{ "setenv", TSETENV },
};

int
yylex(void)
{
	char buf[1024], *ebuf, *p, *str;
	int i, c, quotes = 0, escape = 0, qpos = -1, nonkw = 0;

	p = buf;
	ebuf = buf + sizeof(buf);

repeat:
	/* skip whitespace first */
	for (c = getc(yyfp); c == ' ' || c == '\t'; c = getc(yyfp))
		yylval.colno++;

	/* check for special one-character constructions */
	switch (c) {
		case '\n':
			yylval.colno = 0;
			yylval.lineno++;
			/* FALLTHROUGH */
		case '{':
		case '}':
			return c;
		case '#':
			/* skip comments; NUL is allowed; no continuation */
			while ((c = getc(yyfp)) != '\n')
				if (c == EOF)
					goto eof;
			yylval.colno = 0;
			yylval.lineno++;
			return c;
		case EOF:
			goto eof;
	}

	/* parsing next word */
	for (;; c = getc(yyfp), yylval.colno++) {
		switch (c) {
		case '\0':
			yyerror("unallowed character NUL in column %d",
			    yylval.colno + 1);
			escape = 0;
			continue;
		case '\\':
			escape = !escape;
			if (escape)
				continue;
			break;
		case '\n':
			if (quotes)
				yyerror("unterminated quotes in column %d",
				    qpos + 1);
			if (escape) {
				nonkw = 1;
				escape = 0;
				yylval.colno = 0;
				yylval.lineno++;
				continue;
			}
			goto eow;
		case EOF:
			if (escape)
				yyerror("unterminated escape in column %d",
				    yylval.colno);
			if (quotes)
				yyerror("unterminated quotes in column %d",
				    qpos + 1);
			goto eow;
			/* FALLTHROUGH */
		case '{':
		case '}':
		case '#':
		case ' ':
		case '\t':
			if (!escape && !quotes)
				goto eow;
			break;
		case '"':
			if (!escape) {
				quotes = !quotes;
				if (quotes) {
					nonkw = 1;
					qpos = yylval.colno;
				}
				continue;
			}
		}
		*p++ = c;
		if (p == ebuf) {
			yyerror("too long line");
			p = buf;
		}
		escape = 0;
	}

eow:
	*p = 0;
	if (c != EOF)
		ungetc(c, yyfp);
	if (p == buf) {
		/*
		 * There could be a number of reasons for empty buffer,
		 * and we handle all of them here, to avoid cluttering
		 * the main loop.
		 */
		if (c == EOF)
			goto eof;
		else if (qpos == -1)    /* accept, e.g., empty args: cmd foo args "" */
			goto repeat;
	}
	if (!nonkw) {
		for (i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
			if (strcmp(buf, keywords[i].word) == 0)
				return keywords[i].token;
		}
	}
	if ((str = strdup(buf)) == NULL)
		err(1, "%s", __func__);
	yylval.str = str;
	return TSTRING;

eof:
	if (ferror(yyfp))
		yyerror("input error reading config");
	return 0;
}
#line 456 "usr.bin/doas/parse.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 5:
#line 85 "usr.bin/doas/parse.y"
	{
			struct rule *r;
			r = calloc(1, sizeof(*r));
			if (!r)
				errx(1, "can't allocate rule");
			r->action = yystack.l_mark[-3].action;
			r->options = yystack.l_mark[-3].options;
			r->envlist = yystack.l_mark[-3].envlist;
			r->ident = yystack.l_mark[-2].str;
			r->target = yystack.l_mark[-1].str;
			r->cmd = yystack.l_mark[0].cmd;
			r->cmdargs = yystack.l_mark[0].cmdargs;
			if (nrules == maxrules) {
				if (maxrules == 0)
					maxrules = 63;
				else
					maxrules *= 2;
				if (!(rules = reallocarray(rules, maxrules,
				    sizeof(*rules))))
					errx(1, "can't allocate rules");
			}
			rules[nrules++] = r;
		}
break;
case 6:
#line 109 "usr.bin/doas/parse.y"
	{
			yyval.action = PERMIT;
			yyval.options = yystack.l_mark[0].options;
			yyval.envlist = yystack.l_mark[0].envlist;
		}
break;
case 7:
#line 113 "usr.bin/doas/parse.y"
	{
			yyval.action = DENY;
			yyval.options = 0;
			yyval.envlist = NULL;
		}
break;
case 8:
#line 119 "usr.bin/doas/parse.y"
	{
			yyval.options = 0;
			yyval.envlist = NULL;
		}
break;
case 9:
#line 122 "usr.bin/doas/parse.y"
	{
			yyval.options = yystack.l_mark[-1].options | yystack.l_mark[0].options;
			yyval.envlist = yystack.l_mark[-1].envlist;
			if ((yyval.options & (NOPASS|PERSIST)) == (NOPASS|PERSIST)) {
				yyerror("can't combine nopass and persist");
				YYERROR;
			}
			if (yystack.l_mark[0].envlist) {
				if (yyval.envlist) {
					yyerror("can't have two setenv sections");
					YYERROR;
				} else
					yyval.envlist = yystack.l_mark[0].envlist;
			}
		}
break;
case 10:
#line 137 "usr.bin/doas/parse.y"
	{
			yyval.options = NOPASS;
			yyval.envlist = NULL;
		}
break;
case 11:
#line 140 "usr.bin/doas/parse.y"
	{
			yyval.options = PERSIST;
			yyval.envlist = NULL;
		}
break;
case 12:
#line 143 "usr.bin/doas/parse.y"
	{
			yyval.options = KEEPENV;
			yyval.envlist = NULL;
		}
break;
case 13:
#line 146 "usr.bin/doas/parse.y"
	{
			yyval.options = 0;
			yyval.envlist = yystack.l_mark[-1].strlist;
		}
break;
case 14:
#line 151 "usr.bin/doas/parse.y"
	{
			if (!(yyval.strlist = calloc(1, sizeof(char *))))
				errx(1, "can't allocate strlist");
		}
break;
case 15:
#line 154 "usr.bin/doas/parse.y"
	{
			int nstr = arraylen(yystack.l_mark[-1].strlist);
			if (!(yyval.strlist = reallocarray(yystack.l_mark[-1].strlist, nstr + 2,
			    sizeof(char *))))
				errx(1, "can't allocate strlist");
			yyval.strlist[nstr] = yystack.l_mark[0].str;
			yyval.strlist[nstr + 1] = NULL;
		}
break;
case 16:
#line 164 "usr.bin/doas/parse.y"
	{
			yyval.str = yystack.l_mark[0].str;
		}
break;
case 17:
#line 168 "usr.bin/doas/parse.y"
	{
			yyval.str = NULL;
		}
break;
case 18:
#line 170 "usr.bin/doas/parse.y"
	{
			yyval.str = yystack.l_mark[0].str;
		}
break;
case 19:
#line 174 "usr.bin/doas/parse.y"
	{
			yyval.cmd = NULL;
			yyval.cmdargs = NULL;
		}
break;
case 20:
#line 177 "usr.bin/doas/parse.y"
	{
			yyval.cmd = yystack.l_mark[-1].str;
			yyval.cmdargs = yystack.l_mark[0].cmdargs;
		}
break;
case 21:
#line 182 "usr.bin/doas/parse.y"
	{
			yyval.cmdargs = NULL;
		}
break;
case 22:
#line 184 "usr.bin/doas/parse.y"
	{
			yyval.cmdargs = yystack.l_mark[0].strlist;
		}
break;
#line 812 "usr.bin/doas/parse.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
