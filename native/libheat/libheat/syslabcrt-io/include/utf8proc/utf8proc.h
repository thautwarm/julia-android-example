#ifndef UTF8PROC_H
#define UTF8PROC_H

#include <stdint.h>

/** Unicode categories. */
typedef enum
{
    UTF8PROC_CATEGORY_CN = 0,  /**< Other, not assigned */
    UTF8PROC_CATEGORY_LU = 1,  /**< Letter, uppercase */
    UTF8PROC_CATEGORY_LL = 2,  /**< Letter, lowercase */
    UTF8PROC_CATEGORY_LT = 3,  /**< Letter, titlecase */
    UTF8PROC_CATEGORY_LM = 4,  /**< Letter, modifier */
    UTF8PROC_CATEGORY_LO = 5,  /**< Letter, other */
    UTF8PROC_CATEGORY_MN = 6,  /**< Mark, nonspacing */
    UTF8PROC_CATEGORY_MC = 7,  /**< Mark, spacing combining */
    UTF8PROC_CATEGORY_ME = 8,  /**< Mark, enclosing */
    UTF8PROC_CATEGORY_ND = 9,  /**< Number, decimal digit */
    UTF8PROC_CATEGORY_NL = 10, /**< Number, letter */
    UTF8PROC_CATEGORY_NO = 11, /**< Number, other */
    UTF8PROC_CATEGORY_PC = 12, /**< Punctuation, connector */
    UTF8PROC_CATEGORY_PD = 13, /**< Punctuation, dash */
    UTF8PROC_CATEGORY_PS = 14, /**< Punctuation, open */
    UTF8PROC_CATEGORY_PE = 15, /**< Punctuation, close */
    UTF8PROC_CATEGORY_PI = 16, /**< Punctuation, initial quote */
    UTF8PROC_CATEGORY_PF = 17, /**< Punctuation, final quote */
    UTF8PROC_CATEGORY_PO = 18, /**< Punctuation, other */
    UTF8PROC_CATEGORY_SM = 19, /**< Symbol, math */
    UTF8PROC_CATEGORY_SC = 20, /**< Symbol, currency */
    UTF8PROC_CATEGORY_SK = 21, /**< Symbol, modifier */
    UTF8PROC_CATEGORY_SO = 22, /**< Symbol, other */
    UTF8PROC_CATEGORY_ZS = 23, /**< Separator, space */
    UTF8PROC_CATEGORY_ZL = 24, /**< Separator, line */
    UTF8PROC_CATEGORY_ZP = 25, /**< Separator, paragraph */
    UTF8PROC_CATEGORY_CC = 26, /**< Other, control */
    UTF8PROC_CATEGORY_CF = 27, /**< Other, format */
    UTF8PROC_CATEGORY_CS = 28, /**< Other, surrogate */
    UTF8PROC_CATEGORY_CO = 29, /**< Other, private use */
} utf8proc_category_t;

/** Bidirectional character classes. */
typedef enum
{
    UTF8PROC_BIDI_CLASS_L = 1,    /**< Left-to-Right */
    UTF8PROC_BIDI_CLASS_LRE = 2,  /**< Left-to-Right Embedding */
    UTF8PROC_BIDI_CLASS_LRO = 3,  /**< Left-to-Right Override */
    UTF8PROC_BIDI_CLASS_R = 4,    /**< Right-to-Left */
    UTF8PROC_BIDI_CLASS_AL = 5,   /**< Right-to-Left Arabic */
    UTF8PROC_BIDI_CLASS_RLE = 6,  /**< Right-to-Left Embedding */
    UTF8PROC_BIDI_CLASS_RLO = 7,  /**< Right-to-Left Override */
    UTF8PROC_BIDI_CLASS_PDF = 8,  /**< Pop Directional Format */
    UTF8PROC_BIDI_CLASS_EN = 9,   /**< European Number */
    UTF8PROC_BIDI_CLASS_ES = 10,  /**< European Separator */
    UTF8PROC_BIDI_CLASS_ET = 11,  /**< European Number Terminator */
    UTF8PROC_BIDI_CLASS_AN = 12,  /**< Arabic Number */
    UTF8PROC_BIDI_CLASS_CS = 13,  /**< Common Number Separator */
    UTF8PROC_BIDI_CLASS_NSM = 14, /**< Nonspacing Mark */
    UTF8PROC_BIDI_CLASS_BN = 15,  /**< Boundary Neutral */
    UTF8PROC_BIDI_CLASS_B = 16,   /**< Paragraph Separator */
    UTF8PROC_BIDI_CLASS_S = 17,   /**< Segment Separator */
    UTF8PROC_BIDI_CLASS_WS = 18,  /**< Whitespace */
    UTF8PROC_BIDI_CLASS_ON = 19,  /**< Other Neutrals */
    UTF8PROC_BIDI_CLASS_LRI = 20, /**< Left-to-Right Isolate */
    UTF8PROC_BIDI_CLASS_RLI = 21, /**< Right-to-Left Isolate */
    UTF8PROC_BIDI_CLASS_FSI = 22, /**< First Strong Isolate */
    UTF8PROC_BIDI_CLASS_PDI = 23, /**< Pop Directional Isolate */
} utf8proc_bidi_class_t;

/** Decomposition type. */
typedef enum
{
    UTF8PROC_DECOMP_TYPE_FONT = 1,      /**< Font */
    UTF8PROC_DECOMP_TYPE_NOBREAK = 2,   /**< Nobreak */
    UTF8PROC_DECOMP_TYPE_INITIAL = 3,   /**< Initial */
    UTF8PROC_DECOMP_TYPE_MEDIAL = 4,    /**< Medial */
    UTF8PROC_DECOMP_TYPE_FINAL = 5,     /**< Final */
    UTF8PROC_DECOMP_TYPE_ISOLATED = 6,  /**< Isolated */
    UTF8PROC_DECOMP_TYPE_CIRCLE = 7,    /**< Circle */
    UTF8PROC_DECOMP_TYPE_SUPER = 8,     /**< Super */
    UTF8PROC_DECOMP_TYPE_SUB = 9,       /**< Sub */
    UTF8PROC_DECOMP_TYPE_VERTICAL = 10, /**< Vertical */
    UTF8PROC_DECOMP_TYPE_WIDE = 11,     /**< Wide */
    UTF8PROC_DECOMP_TYPE_NARROW = 12,   /**< Narrow */
    UTF8PROC_DECOMP_TYPE_SMALL = 13,    /**< Small */
    UTF8PROC_DECOMP_TYPE_SQUARE = 14,   /**< Square */
    UTF8PROC_DECOMP_TYPE_FRACTION = 15, /**< Fraction */
    UTF8PROC_DECOMP_TYPE_COMPAT = 16,   /**< Compat */
} utf8proc_decomp_type_t;

/** Boundclass property. (TR29) */
typedef enum
{
    UTF8PROC_BOUNDCLASS_START = 0,               /**< Start */
    UTF8PROC_BOUNDCLASS_OTHER = 1,               /**< Other */
    UTF8PROC_BOUNDCLASS_CR = 2,                  /**< Cr */
    UTF8PROC_BOUNDCLASS_LF = 3,                  /**< Lf */
    UTF8PROC_BOUNDCLASS_CONTROL = 4,             /**< Control */
    UTF8PROC_BOUNDCLASS_EXTEND = 5,              /**< Extend */
    UTF8PROC_BOUNDCLASS_L = 6,                   /**< L */
    UTF8PROC_BOUNDCLASS_V = 7,                   /**< V */
    UTF8PROC_BOUNDCLASS_T = 8,                   /**< T */
    UTF8PROC_BOUNDCLASS_LV = 9,                  /**< Lv */
    UTF8PROC_BOUNDCLASS_LVT = 10,                /**< Lvt */
    UTF8PROC_BOUNDCLASS_REGIONAL_INDICATOR = 11, /**< Regional indicator */
    UTF8PROC_BOUNDCLASS_SPACINGMARK = 12,        /**< Spacingmark */
    UTF8PROC_BOUNDCLASS_PREPEND = 13,            /**< Prepend */
    UTF8PROC_BOUNDCLASS_ZWJ = 14,                /**< Zero Width Joiner */

    /* the following are no longer used in Unicode 11, but we keep
       the constants here for backward compatibility */
    UTF8PROC_BOUNDCLASS_E_BASE = 15,         /**< Emoji Base */
    UTF8PROC_BOUNDCLASS_E_MODIFIER = 16,     /**< Emoji Modifier */
    UTF8PROC_BOUNDCLASS_GLUE_AFTER_ZWJ = 17, /**< Glue_After_ZWJ */
    UTF8PROC_BOUNDCLASS_E_BASE_GAZ = 18,     /**< E_BASE + GLUE_AFTER_ZJW */

    /* the Extended_Pictographic property is used in the Unicode 11
       grapheme-boundary rules, so we store it in the boundclass field */
    UTF8PROC_BOUNDCLASS_EXTENDED_PICTOGRAPHIC = 19,
    UTF8PROC_BOUNDCLASS_E_ZWG = 20, /* UTF8PROC_BOUNDCLASS_EXTENDED_PICTOGRAPHIC + ZWJ */
} utf8proc_boundclass_t;

/** Indic_Conjunct_Break property. (TR44) */
typedef enum
{
    UTF8PROC_INDIC_CONJUNCT_BREAK_NONE = 0,
    UTF8PROC_INDIC_CONJUNCT_BREAK_LINKER = 1,
    UTF8PROC_INDIC_CONJUNCT_BREAK_CONSONANT = 2,
    UTF8PROC_INDIC_CONJUNCT_BREAK_EXTEND = 3,
} utf8proc_indic_conjunct_break_t;

typedef int16_t utf8proc_int16_t;
typedef uint16_t utf8proc_uint16_t;
typedef int32_t utf8proc_int32_t;

/** Holds the value of a property. */
typedef utf8proc_int16_t utf8proc_propval_t;

/** Struct containing information about a codepoint. */
typedef struct utf8proc_property_struct
{
    /**
     * Unicode category.
     * @see utf8proc_category_t.
     */
    utf8proc_propval_t category;
    utf8proc_propval_t combining_class;
    /**
     * Bidirectional class.
     * @see utf8proc_bidi_class_t.
     */
    utf8proc_propval_t bidi_class;
    /**
     * @anchor Decomposition type.
     * @see utf8proc_decomp_type_t.
     */
    utf8proc_propval_t decomp_type;
    utf8proc_uint16_t decomp_seqindex;
    utf8proc_uint16_t casefold_seqindex;
    utf8proc_uint16_t uppercase_seqindex;
    utf8proc_uint16_t lowercase_seqindex;
    utf8proc_uint16_t titlecase_seqindex;
    utf8proc_uint16_t comb_index;
    unsigned bidi_mirrored : 1;
    unsigned comp_exclusion : 1;
    /**
     * Can this codepoint be ignored?
     * Used by @ref utf8proc_decompose_char when @ref UTF8PROC_IGNORE is
     * passed as an option.
     */
    unsigned ignorable : 1;
    unsigned control_boundary : 1;
    /** The width of the codepoint. */
    unsigned charwidth : 2;
    unsigned pad : 2;
    /**
     * Boundclass.
     * @see utf8proc_boundclass_t.
     */
    unsigned boundclass : 6;
    unsigned indic_conjunct_break : 2;
} utf8proc_property_t;

int32_t utf8proc_charwidth(utf8proc_int32_t codepoint);
int32_t utf8proc_category(utf8proc_int32_t c);
#endif