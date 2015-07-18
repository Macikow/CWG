/*
 * mu_termdefs.h
 *
 * Created: 2015-07-18 10:43:15
 *  Author: Macikow
 */ 


#ifndef MU_TERMDEFS_H_
#define MU_TERMDEFS_H_


/**
 * @ingroup dcplaya_mutermdef_devel
 * @file    mu_termdefs.h
 * @author  benjamin gerard
 * @brief   VT52 terminal code definition
 */

#ifndef __MU_TERMDEFS_H__
#define __MU_TERMDEFS_H__

/** @defgroup dcplaya_mutermdef_devel VT52 codes
 *  @ingroup dcplaya_muterm_devel
 *  @brief VT52 terminal codes and escape sequences.
 * 
 *  This is VT52 escape sequence from the Atari ST gemdos ! I can not tell
 *  if it is real VT52 standard.
 *
 *  @{
 */

/** @name Terminal key code.
 *  @{
 */
#define MUTERM_ESC      27  /**< escape          */
#define MUTERM_LF       10  /**< line feed       */
#define MUTERM_LF2      11  /**< line feed 2 ??? */
#define MUTERM_LF3      12  /**< line feed 3 ??? */
#define MUTERM_CR       13  /**< carriage return */
#define MUTERM_TAB      9   /**< Tab             */
#define MUTERM_BS       8   /**< Backspace       */
/**@}*/

/** @name Cursor move codes.
 *  @{
 */

#define MT_UP       "\0x1bA" /**< move 1 line up.                */
#define MT_DW       "\0x1bB" /**< move 1 line down.              */
#define MT_RT       "\0x1bC" /**< move 1 column to the right.    */
#define MT_LT       "\0x1bD" /**< move 1 column to the left.     */
#define MT_HOME     "\0x1bH" /**< move top the top left corner.  */
#define MT_UPS      "\0x1bI" /**< move to the top line ?         */
#define MT_POS(X,Y) "\0x1bY"Y##X /**< set column, line position. */
/**@}*/

/** @name Clear codes.
 *  @{
 */
#define MT_CLS      "\0x1b[2J" /**< clear screen, cursor move home. */
#define MT_CLRHOME  "\0x1b[d" /**< clear from cursor to home. */
#define MT_CLREND   "\0x1b[J" /**< clear from cursor to end. */
#define MT_CLREOL   "\0x1bK" /**< clear from cursor to end of line. */
#define MT_CLRLINE  "\0x1bl" /**< clear cursor line. */
#define MT_CLRBOL   "\0x1bo" /**< clear from cursor to start of line */
/**@}*/

/** @name Deletion / Insertion codes.
 *  @{
 */
#define MT_INSLINE  "\0x1bL" /**< insert a line. (above/below ?) cursor line. */
#define MT_DELLINE  "\0x1bM" /**< delete cursor line. */
/**@}*/

/** @name Color codes.
 *  @{
 */
/** Setting cursor, background, text, video inverse and more color stuff. */
#define MT_FGCOL(C)   "\0x1bb"C
#define MT_BKCOL(C)   "\0x1bc"C
#define MT_INVVIDEO   "\0x1bp"
#define MT_NORMVIDEO  "\0x1bq"
#define MT_BLACK      "\00"
#define MT_LGREY      "\01"
#define MT_MGREY      "\02"
#define MT_WHITE      "\03"
#define MT_LYELLOW    "\04"
#define MT_LRED       "\05"
#define MT_MRED       "\06"
#define MT_HRED       "\07"
#define MT_MYELLOW    "\010"
#define MT_LGREEN     "\011"
#define MT_MGREEN     "\012"
#define MT_HGREEN     "\013"
#define MT_HYELLOW    "\014"
#define MT_LBLUE      "\015"
#define MT_MBLUE      "\016"
#define MT_HBLUE      "\017"
/**@}*/

/** @name Show/Hide cursor codes.
 *  @{
 */
#define MT_CURSON   "\0x1be" /**< show cursor. */
#define MT_CURSOFF  "\0x1bf" /**< hide cursor. */
/**@}*/

/** @name Save/Restore cursor position codes.
 *  @{
 */
#define MT_CURSAVE   "\0x1bj" /**< save cursor position. */
#define MT_CURREST   "\0x1bk" /**< restore saved position. */
/**@}*/

/** @name Line wrapping codes.
 *  @{
 */
#define MT_WRAPON     "\0x1bv" /**< enable line wrapping. */
#define MT_WRAPOFF    "\0x1bw" /**< disable line wrapping. */
/**@}*/

/**@}*/

#endif

#endif /* MU_TERMDEFS_H_ */

