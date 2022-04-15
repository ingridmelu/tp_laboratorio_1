/*
 * datos.h
 *
 *  Created on: 12 abr 2022
 *      Author: Familia
 */

#ifndef DATOS_H_
#define DATOS_H_
/// @fn opcionTres(float, float, float, float, float, float , float , float , float .float , float , float)
/// @brief Realiza los calculos utilizando la variables kilometros, precioLatam, precioAerolineas
///
/// @param descuentoLatam, aumentoLatam, btcLatam, unitarioLatam, descuentoAerolineas, AumentoAerolineas, btcAerolineas, unitarioLatam, diferenciaPrecio
void opcionTres(float precioLatam, float precioAerolineas, float kilometros, float* descuentoLatam, float* aumentoLatam,float* btcLatam, float* unitarioLatam,float* descuentoAerolineas, float* aumentoAerolineas,float* btcAerolineas,float* unitarioAerolineas, float* diferencia);
/// @fn opcionCuatro(float, float, float, float, float, float , float , float , float .float , float , float)
/// @brief Muestras los datos recibidos de la opcionTres
///
/// @param descuentoLatam, aumentoLatam, btcLatam, unitarioLatam, descuentoAerolineas, AumentoAerolineas, btcAerolineas, unitarioLatam, diferenciaPrecio
void opcionCuatro(float precioLatam,float precioAerolineas,float kilometros,float descuentoLatam,float aumentoLatam,float btcLatam,float unitarioLatam,float descuentoAerolineas,float aumentoAerolineas,float btcAerolineas,float unitarioAerolineas,float diferencia);
#endif /* DATOS_H_ */
