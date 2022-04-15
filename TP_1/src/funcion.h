/*
 * funcion.h
 *
 *  Created on: 8 abr 2022
 *      Author: Familia
 */

#ifndef FUNCION_H_
#define FUNCION_H_
/// @fn descuentoDebito(float)
/// @brief Le hace un descuento a los vuelos
///
/// @param descuentoLatam, descuentoAerolineas
/// @return Precio con descuento
float descuentoDebito(float precio);

/// @fn aumentoCredito(float)
/// @brief Le hace un aumento a los vuelos
///
/// @param aumentoLatam, aumentoAerolineas
/// @return Precio con aumento
float aumentoCredito(float importe);

/// @fn divisionBitcoin(float)
/// @brief convierte los pesos AR a bitcoin
///
/// @param btcLatam, btcAerolineas
/// @return Precio con bitcoin
float divisionBitcoin(float precio);

/// @fn precioPorKm(float, float)
/// @brief La division de precio y kilometros
///
/// @param unitarioLatam, unitarioAerolineas
/// @return precio unitario
float precioPorKm(float precio, float kilometros);

/// @fn diferenciaPrecio(float, float)
/// @brief Calcula la diferencia de precio de latam y aerolineas
///
/// @param diferenciaPrecio
/// @return Diferencia de precio
float diferenciaPrecio(float latam, float aerolineas);

#endif /* FUNCION_H_ */
