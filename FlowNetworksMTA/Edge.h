#pragma once
class Edge
{
	int startVertex, endVertex, flow, cut;
	int kibulShiuri = 0;

public:
	Edge(int _startVertex, int _endVertex, int _flow, int _cut) : startVertex(_startVertex), endVertex(_endVertex), flow(_flow), cut(_cut) {}
	int getStart() { return startVertex; }
	int getEnd() { return endVertex; }
	int getFlow() { return flow; }
	int getCut() { return cut; }
	int getKibulShiuri() { return kibulShiuri; }
	void setKibulShiuri(int _kibulShiuri) { kibulShiuri = _kibulShiuri; }
	void setFlow(int _flow) { flow = _flow; }
};

