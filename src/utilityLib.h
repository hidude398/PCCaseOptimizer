#ifndef utilityLib
#define utilityLib
#endif

namespace utilities 
{
class airFunctions 
{
public:
	template <typename T>
	static T massFlow (T pressure, T density);
	/* Calculates the flow of mass given the volume flowing plus
	 * the density of the gas. */

	static float estSaturationVaporPressure (float temperature);
	/* Utilizes the Herman Wobus method to calculate satruation
	 * vapor pressure of water at a given temperature. This is accurate
	 * between -50 < T < 100, given a T in celsius. Return value is
	 * given in mbar */

	template <typename T>
	static T waterVaporPressure (T saturationVaporPressure, int relativeHumidity);
	/* Returns the actual water vapor pressure given a saturation vapor
	 * pressure and the measured relative humididty for the air
	 * conditions. Throws exception std::range_error if relative humididty isn't a valid decimal */

	template <typename T>
	static T dryAirPressure (T totalPressure, T waterVaporPressure);
	/* Returns the partial pressure of dry air given a total pressure
	 * and the known water vapor pressure in the gas */

	template <typename T>
	static T rho (T dryAirPressure, T waterVaporPressure, T temperature);
	/* Given a particular set of pressures and a temperature in kelvin,
	 * returns the density of air in kg/m^3 */

	template <typename T>
	static T flowVelocity (T volumeFlow, T area);
	/* Given a volume flow and the outlet area, calculate the flow
	 * velocity. For numerical accuracy the volume and area units must
	 * derive from the same unit of measure. For example, cubic meters
	 * square meters will be numerically correct, while cubic meters and
	 * square feet will need a correction factor applied to be accurate */
};
} 
