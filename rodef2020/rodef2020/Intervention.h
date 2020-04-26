#pragma once

#include <string>
#include <vector>

/*
 * class Intervention:
 */
class Intervention
{
public:
	Intervention(const std::string& ar_name,
		int a_tmax,
		const std::vector<int>& ar_delta,
		std::vector<std::vector<std::vector<double>>>& ap_workloads,
		std::vector<std::vector<std::vector<double>>>& ap_risks);
	~Intervention();

	std::string getName() const { return m_name; }
	int getTMax() const { return m_tmax; }
	int getDelta_it(int a_t) const { return m_delta[a_t-1]; }
	double getWorkload(int a_c, int a_t, int a_st) { return mp_workloads->at(a_c).at(a_t - 1).at(a_st - 1); }
	double getRisk(int a_s, int a_t, int a_st) { return mp_risks->at(a_s).at(a_t - 1).at(a_st - 1); }
	std::vector<int> getDelta() { return m_delta; };
	std::vector<std::vector<std::vector<double>>> *getRisks() { return mp_risks; };
private:
	std::string m_name;
	int m_tmax;
	std::vector<int> m_delta;
	std::vector<std::vector<std::vector<double>>> *mp_workloads;	// workloads on the intervention, indexed by [c][t][st]
	std::vector<std::vector<std::vector<double>>> *mp_risks;		// risks on the intervention, indexed by [s][t][st]
	
};
