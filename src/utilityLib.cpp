#include <cmath>
#include <exception>
namespace utilities {

	template <typename T>
	T airFunctions::massFlow (T pressure, T density) 
	{
		return (pressure * density);
	}

	float airFunctions::estSaturationVaporPressure (float temperature)
	{
		float pol = 0.99999683f + (
				temperature * ((-.90826951/ std::pow(10,2)) 
					+ temperature * ((.78736169/ std::pow(10,4))
						+ temperature * ((-.61117985 / std::pow(10,6))
							+ temperature * ((.43884187/ std::pow(10,8))
								+ temperature * ((.29883885 / std::pow(10, 10))
									+ temperature * ((.21874425 / std::pow(10,12)) 
											+ temperature * ((-.17892321/ std::pow(10,14))
												+ temperature * ((.11112018 / std::pow(10,16))
													+ temperature * ((-.30994571/std::pow(10,19)
													)
												)
											)
										)
									)
								)
							)
						)
					)
				)
		);

		float es0 = 6.1078f;
		return (es0 / std::pow(pol, 8));
	}
	

	template <typename T>
	T airFunctions::waterVaporPressure (T saturationVaporPressure, int relativeHumidity)
	{
		if (relativeHumidity < 0 || relativeHumidity > 100)
		{
			throw (std::exception::range_error);
		}	
		return (saturationVaporPressure * relativeHumidity);
	}

	template <typename T>
	T airFunctions::dryAirPressure (T totalAirPressure, T waterVaporPressure)
	{
		return (totalAirPressure - waterVaporPressure);
	}

	template <typename T>
	T airFunctions::rho (T dryAirPressure, T waterVaporPressure, T temperature)
	{
		const float dryAirGasConstant = 287.058f;
		const float waterVaporGasConstant = 461.495f;
		return (
			(dryAirPressure/(dryAirGasConstant * temperature))
			+ (waterVaporPressure/(waterVaporGasConstant * temperature))
		);
	}

	template <typename T>
	T airFunctions::flowVelocity (T volumeFlow, T area)
	{
		return (volumeFlow/area);
	}
	
}
