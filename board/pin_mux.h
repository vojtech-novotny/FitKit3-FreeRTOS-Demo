/// @author Vojtěch Novotný - xnovot1f
/// @changes 50%
/// Routing information for GPIO ports and processor pins.
/// @date 23.12.2019

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/*! @name PORTB2 (coord G12), D12
  @{ */
#define BOARD_INITPINS_D12_GPIO GPIOB /*!<@brief GPIO device name: GPIOB */
#define BOARD_INITPINS_D12_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_D12_PIN 2U     /*!<@brief PORTB pin index: 2 */
                                      /* @} */

/*! @name PORTB3 (coord G11), D11
  @{ */
#define BOARD_INITPINS_D11_GPIO GPIOB /*!<@brief GPIO device name: GPIOB */
#define BOARD_INITPINS_D11_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_D11_PIN 3U     /*!<@brief PORTB pin index: 3 */
                                      /* @} */

/*! @name PORTB4 (coord G10), D10
  @{ */
#define BOARD_INITPINS_D10_GPIO GPIOB /*!<@brief GPIO device name: GPIOB */
#define BOARD_INITPINS_D10_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_D10_PIN 4U     /*!<@brief PORTB pin index: 4 */
                                      /* @} */

/*! @name PORTB5 (coord G9), D9
  @{ */
#define BOARD_INITPINS_D9_GPIO GPIOB /*!<@brief GPIO device name: GPIOB */
#define BOARD_INITPINS_D9_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_D9_PIN 5U     /*!<@brief PORTB pin index: 5 */
                                     /* @} */

/*! @name PORTE10 (coord F1), SW2
  @{ */
#define BOARD_INITPINS_SW2_GPIO GPIOE /*!<@brief GPIO device name: GPIOE */
#define BOARD_INITPINS_SW2_PORT PORTE /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_SW2_PIN 10U    /*!<@brief PORTE pin index: 10 */
                                      /* @} */

/*! @name PORTE11 (coord G4), SW6
  @{ */
#define BOARD_INITPINS_SW6_GPIO GPIOE /*!<@brief GPIO device name: GPIOE */
#define BOARD_INITPINS_SW6_PORT PORTE /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_SW6_PIN 11U    /*!<@brief PORTE pin index: 11 */
                                      /* @} */

/*! @name PORTE12 (coord G3), SW3
  @{ */
#define BOARD_INITPINS_SW3_GPIO GPIOE /*!<@brief GPIO device name: GPIOE */
#define BOARD_INITPINS_SW3_PORT PORTE /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_SW3_PIN 12U    /*!<@brief PORTE pin index: 12 */
                                      /* @} */

/*! @name PORTE26 (coord K4), SW5
  @{ */
#define BOARD_INITPINS_SW5_GPIO GPIOE /*!<@brief GPIO device name: GPIOE */
#define BOARD_INITPINS_SW5_PORT PORTE /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_SW5_PIN 26U    /*!<@brief PORTE pin index: 26 */
                                      /* @} */

/*! @name PORTE27 (coord J4), SW4
  @{ */
#define BOARD_INITPINS_SW4_GPIO GPIOE /*!<@brief GPIO device name: GPIOE */
#define BOARD_INITPINS_SW4_PORT PORTE /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_SW4_PIN 27U    /*!<@brief PORTE pin index: 27 */
                                      /* @} */

/*! @name PORTA4 (coord L7), Speaker
  @{ */
#define BOARD_INITPINS_Speaker_GPIO GPIOA /*!<@brief GPIO device name: GPIOA */
#define BOARD_INITPINS_Speaker_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_Speaker_PIN 4U     /*!<@brief PORTA pin index: 4 */
                                          /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
