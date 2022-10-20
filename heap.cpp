//.h file code:
/* */

#include <string>
#include <unordered_map>
#include <vector>
#include <list>
#include <iostream>
#include <cmath>
#include <limits>
#include <cctype>
#include <stdexcept>
#include <optional>
#include <memory>


	class Graph_M
	{
	public:
		class Vertex
		{
		private:
			std::shared_ptr<Graph_M> outerInstance;

		public:
			Vertex(std::shared_ptr<Graph_M> outerInstance);

			std::unordered_map<std::wstring, int> nbrs = std::unordered_map<std::wstring, int>();
		};

	public:
		static std::unordered_map<std::wstring, std::shared_ptr<Vertex>> vtces;

		Graph_M();

		virtual int numVetex();

		virtual bool containsVertex(const std::wstring &vname);

		virtual void addVertex(const std::wstring &vname);

		virtual void removeVertex(const std::wstring &vname);

		virtual int numEdges();

		virtual bool containsEdge(const std::wstring &vname1, const std::wstring &vname2);

		virtual void addEdge(const std::wstring &vname1, const std::wstring &vname2, int value);

		virtual void removeEdge(const std::wstring &vname1, const std::wstring &vname2);





Graph_M::Vertex::Vertex(std::shared_ptr<Graph_M> outerInstance) : outerInstance(outerInstance)
{
}

std::unordered_map<std::wstring, std::shared_ptr<Vertex>> Graph_M::vtces;

Graph_M::Graph_M()
{
	vtces = std::unordered_map<std::wstring, Vertex>();
}

int Graph_M::numVetex()
{
	return this->vtces->size();
}

bool Graph_M::containsVertex(const std::wstring &vname)
{
	return this->vtces.find(vname) != this->vtces.end();
}

void Graph_M::addVertex(const std::wstring &vname)
{
	std::shared_ptr<Vertex> vtx = std::make_shared<Vertex>(shared_from_this());
	vtces.emplace(vname, vtx);
}

void Graph_M::removeVertex(const std::wstring &vname)
{
	std::shared_ptr<Vertex> vtx = vtces[vname];
	std::vector<std::wstring> keys(vtx->nbrs.keySet());

	for (auto key : keys)
	{
		std::shared_ptr<Vertex> nbrVtx = vtces[key];
		nbrVtx->nbrs.erase(vname);
	}

	vtces.erase(vname);
}

int Graph_M::numEdges()
{
	std::vector<std::wstring> keys(vtces.keySet());
	int count = 0;

	for (auto key : keys)
	{
		std::shared_ptr<Vertex> vtx = vtces[key];
		count = count + vtx->nbrs.size();
	}

	return count / 2;
}

bool Graph_M::containsEdge(const std::wstring &vname1, const std::wstring &vname2)
{
	std::shared_ptr<Vertex> vtx1 = vtces[vname1];
	std::shared_ptr<Vertex> vtx2 = vtces[vname2];

	if (vtx1 == nullptr || vtx2 == nullptr || vtx1->nbrs.find(vname2) == vtx1->nbrs.end())
	{
		return false;
	}

	return true;
}

void Graph_M::addEdge(const std::wstring &vname1, const std::wstring &vname2, int value)
{
	std::shared_ptr<Vertex> vtx1 = vtces[vname1];
	std::shared_ptr<Vertex> vtx2 = vtces[vname2];

	if (vtx1 == nullptr || vtx2 == nullptr || vtx1->nbrs.find(vname2) != vtx1->nbrs.end())
	{
		return;
	}

	vtx1->nbrs.emplace(vname2, value);
	vtx2->nbrs.emplace(vname1, value);
}

void Graph_M::removeEdge(const std::wstring &vname1, const std::wstring &vname2)
{
	std::shared_ptr<Vertex> vtx1 = vtces[vname1];
	std::shared_ptr<Vertex> vtx2 = vtces[vname2];

	//check if the vertices given or the edge between these vertices exist or not
	if (vtx1 == nullptr || vtx2 == nullptr || vtx1->nbrs.find(vname2) == vtx1->nbrs.end())
	{
		return;
	}

	vtx1->nbrs.erase(vname2);
	vtx2->nbrs.erase(vname1);
}
public:
virtual void display_Map();

		virtual void display_Stations();

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

		virtual bool hasPath(const std::wstring &vname1, const std::wstring &vname2, std::unordered_map<std::wstring, bool> &processed);


		class DijkstraPair : public Comparable<std::shared_ptr<DijkstraPair>>
		{
		public:
			std::wstring vname;
			std::wstring psf;
			int cost = 0;

			/*
			The compareTo method is defined in Java.lang.Comparable.
			Here, we override the method because the conventional compareTo method
			is used to compare strings,integers and other primitive data types. But
			here in this case, we intend to compare two objects of DijkstraPair class.
			*/ 

			/*
			Removing the overriden method gives us this errror:
			The type Graph_M.DijkstraPair must implement the inherited abstract method Comparable<Graph_M.DijkstraPair>.compareTo(Graph_M.DijkstraPair)
			This is because DijkstraPair is not an abstract class and implements Comparable interface which has an abstract 
			method compareTo. In order to make our class concrete(a class which provides implementation for all its methods)
			we have to override the method compareTo
			 */
			int compareTo(std::shared_ptr<DijkstraPair> o) override;
		};





void <missing_class_definition>::display_Map()
{
			std::wcout << L"\t Kolkata Metro Map" << std::endl;
			std::wcout << L"\t------------------" << std::endl;
			std::wcout << L"----------------------------------------------------\n" << std::endl;
			std::vector<std::wstring> keys(vtces::keySet());

			for (auto key : keys)
			{
				std::wstring str = key + L" =>\n";
				std::shared_ptr<Vertex> vtx = vtces->get(key);
				std::vector<std::wstring> vtxnbrs(vtx->nbrs.keySet());

				for (auto nbr : vtxnbrs)
				{
					str = str + L"\t" + nbr + L"\t";
								if (nbr.length() < 16)
								{
								str = str + L"\t";
								}
								if (nbr.length() < 8)
								{
								str = str + L"\t";
								}
								str = str + vtx->nbrs->get(nbr) + L"\n";
				}
				std::wcout << str << std::endl;
			}
			std::wcout << L"\t------------------" << std::endl;
			std::wcout << L"---------------------------------------------------\n" << std::endl;

}

void <missing_class_definition>::display_Stations()
{
	std::wcout << L"\n***********************************************************************\n" << std::endl;
	std::vector<std::wstring> keys(vtces::keySet());
	int i = 1;
	for (auto key : keys)
	{
		std::wcout << i << L". " << key << std::endl;
		i++;
	}
	std::wcout << L"\n***********************************************************************\n" << std::endl;
}

bool <missing_class_definition>::hasPath(const std::wstring &vname1, const std::wstring &vname2, std::unordered_map<std::wstring, bool> &processed)
{
	// DIR EDGE
	if (containsEdge(vname1, vname2))
	{
		return true;
	}

	//MARK AS DONE
	processed.emplace(vname1, true);

	std::shared_ptr<Vertex> vtx = vtces->get(vname1);
	std::vector<std::wstring> nbrs(vtx->nbrs.keySet());

	//TRAVERSE THE NBRS OF THE VERTEX
	for (auto nbr : nbrs)
	{

		if (processed.find(nbr) == processed.end())
		{
			if (hasPath(nbr, vname2, processed))
			{
				return true;
			}
		}
	}

	return false;
}

int DijkstraPair::compareTo(std::shared_ptr<DijkstraPair> o)
{
	return o->cost - this->cost;
}
public:
virtual int dijkstra(const std::wstring &src, const std::wstring &des, bool nan);

		class Pair
		{
		public:
			std::wstring vname;
			std::wstring psf;
			int min_dis = 0;
			int min_time = 0;
		};

	public:
		virtual std::wstring Get_Minimum_Distance(const std::wstring &src, const std::wstring &dst);




int <missing_class_definition>::dijkstra(const std::wstring &src, const std::wstring &des, bool nan)
{
			int val = 0;
			std::vector<std::wstring> ans;
			std::unordered_map<std::wstring, std::shared_ptr<DijkstraPair>> map;

			std::shared_ptr<Heap<std::shared_ptr<DijkstraPair>>> heap = std::make_shared<Heap<std::shared_ptr<DijkstraPair>>>();

			for (std::wstring key : vtces::keySet())
			{
				std::shared_ptr<DijkstraPair> np = std::make_shared<DijkstraPair>();
				np->vname = key;
				//np.psf = "";
				np->cost = std::numeric_limits<int>::max();

				if (key.equals(src))
				{
					np->cost = 0;
					np->psf = key;
				}

				heap->add(np);
				map.emplace(key, np);
			}

			//keep removing the pairs while heap is not empty
			while (!heap->isEmpty())
			{
				std::shared_ptr<DijkstraPair> rp = heap->remove();

				if (rp->vname.equals(des))
				{
					val = rp->cost;
					break;
				}

				map.erase(rp->vname);

				ans.push_back(rp->vname);

				std::shared_ptr<Vertex> v = vtces->get(rp->vname);
				for (std::wstring nbr : v->nbrs.keySet())
				{
					if (map.find(nbr) != map.end())
					{
						int oc = map[nbr]->cost;
						std::shared_ptr<Vertex> k = vtces->get(rp->vname);
						int nc;
						if (nan)
						{
							nc = rp->cost + 120 + 40 * k->nbrs->get(nbr);
						}
						else
						{
							nc = rp->cost + k->nbrs->get(nbr);
						}

						if (nc < oc)
						{
							std::shared_ptr<DijkstraPair> gp = map[nbr];
							gp->psf = rp->psf + nbr;
							gp->cost = nc;

							heap->updatePriority(gp);
						}
					}
				}
			}
			return val;
}

std::wstring <missing_class_definition>::Get_Minimum_Distance(const std::wstring &src, const std::wstring &dst)
{
	int min = std::numeric_limits<int>::max();
	//int time = 0;
	std::wstring ans = L"";
	std::unordered_map<std::wstring, bool> processed;
	std::list<std::shared_ptr<Pair>> stack;

	// create a new pair
	std::shared_ptr<Pair> sp = std::make_shared<Pair>();
	sp->vname = src;
	sp->psf = src + L"  ";
	sp->min_dis = 0;
	sp->min_time = 0;

	// put the new pair in stack
	stack.push_front(sp);

	// while stack is not empty keep on doing the work
	while (!stack.empty())
	{
		// remove a pair from stack
		std::shared_ptr<Pair> rp = stack.pop_front();

		if (processed.find(rp->vname) != processed.end())
		{
			continue;
		}

		// processed put
		processed.emplace(rp->vname, true);

		//if there exists a direct edge b/w removed pair and destination vertex
		if (rp->vname == dst)
		{
			int temp = rp->min_dis;
			if (temp < min)
			{
				ans = rp->psf;
				min = temp;
			}
			continue;
		}

		std::shared_ptr<Vertex> rpvtx = vtces->get(rp->vname);
		std::vector<std::wstring> nbrs(rpvtx->nbrs.keySet());

		for (auto nbr : nbrs)
		{
			// process only unprocessed nbrs
			if (processed.find(nbr) == processed.end())
			{

				// make a new pair of nbr and put in queue
				std::shared_ptr<Pair> np = std::make_shared<Pair>();
				np->vname = nbr;
				np->psf = rp->psf + nbr + L"  ";
				np->min_dis = rp->min_dis + rpvtx->nbrs->get(nbr);
				//np.min_time = rp.min_time + 120 + 40*rpvtx.nbrs.get(nbr); 
				stack.push_front(np);
			}
		}
	}

	ans = ans + Integer::toString(min);
	return ans;
}
public:
virtual std::wstring Get_Minimum_Time(const std::wstring &src, const std::wstring &dst);

		virtual std::vector<std::wstring> get_Interchanges(const std::wstring &str);





std::wstring <missing_class_definition>::Get_Minimum_Time(const std::wstring &src, const std::wstring &dst)
{
			int min = std::numeric_limits<int>::max();
			std::wstring ans = L"";
			std::unordered_map<std::wstring, bool> processed;
			std::list<std::shared_ptr<Pair>> stack;

			// create a new pair
			std::shared_ptr<Pair> sp = std::make_shared<Pair>();
			sp->vname = src;
			sp->psf = src + L"  ";
			sp->min_dis = 0;
			sp->min_time = 0;

			// put the new pair in queue
			stack.push_front(sp);

			// while queue is not empty keep on doing the work
			while (!stack.empty())
			{

				// remove a pair from queue
				std::shared_ptr<Pair> rp = stack.pop_front();

				if (processed.find(rp->vname) != processed.end())
				{
					continue;
				}

				// processed put
				processed.emplace(rp->vname, true);

				//if there exists a direct edge b/w removed pair and destination vertex
				if (rp->vname.equals(dst))
				{
					int temp = rp->min_time;
					if (temp < min)
					{
						ans = rp->psf;
						min = temp;
					}
					continue;
				}

				std::shared_ptr<Vertex> rpvtx = vtces->get(rp->vname);
				std::vector<std::wstring> nbrs(rpvtx->nbrs.keySet());

				for (auto nbr : nbrs)
				{
					// process only unprocessed nbrs
					if (processed.find(nbr) == processed.end())
					{

						// make a new pair of nbr and put in queue
						std::shared_ptr<Pair> np = std::make_shared<Pair>();
						np->vname = nbr;
						np->psf = rp->psf + nbr + L"  ";
						//np.min_dis = rp.min_dis + rpvtx.nbrs.get(nbr);
						np->min_time = rp->min_time + 120 + 40 * rpvtx->nbrs->get(nbr);
						stack.push_front(np);
					}
				}
			}
			std::optional<double> minutes = std::ceil(static_cast<double>(min) / 60);

			ans = ans + Double::toString(minutes);
			return ans;
}

std::vector<std::wstring> <missing_class_definition>::get_Interchanges(const std::wstring &str)
{
	std::vector<std::wstring> arr;
	std::vector<std::wstring> res = str.split(L"  ");
	arr.push_back(res[0]);
	int count = 0;
	for (int i = 1;i < res.size() - 1;i++)
	{
		int index = (int)res[i].find(L'~');
		std::wstring s = res[i].substr(index + 1);

		if (s.length() == 2)
		{
			std::wstring prev = res[i - 1].substr((int)res[i - 1].find(L'~') + 1);
			std::wstring next = res[i + 1].substr((int)res[i + 1].find(L'~') + 1);

			if (prev == next)
			{
				arr.push_back(res[i]);
			}
			else
			{
				arr.push_back(res[i] + L" ==> " + res[i + 1]);
				i++;
				count++;
			}
		}
		else
		{
			arr.push_back(res[i]);
		}
	}

	arr.push_back(Integer::toString(count));
	arr.push_back(res[res.size() - 1]);
	return arr;
}
public:
static void Create_Metro_Map(std::shared_ptr<Graph_M> g);

		static std::vector<std::wstring> printCodelist();





void <missing_class_definition>::Create_Metro_Map(std::shared_ptr<Graph_M> g)
{
			g->addVertex(L" Sector 5~B");
			g->addVertex(L"Botanical Garden~B");
			g->addVertex(L"Ganga River~B");
			g->addVertex(L"Bhawanipur~BY");
			g->addVertex(L"Alipore~B");
			g->addVertex(L"Behala~B");
			g->addVertex(L"Howrah~BO");
			g->addVertex(L"Salt Lake~B");
			g->addVertex(L" City Center 2~Y");
			g->addVertex(L"Kasba~Y");
			g->addVertex(L"Gariahat~Y");
			g->addVertex(L"Garia~Y");
			g->addVertex(L"Park street~YO");
			g->addVertex(L"SSKM Hospita~Y");
			g->addVertex(L"Eden Gardens Stadium~O");
			g->addVertex(L"Sealdah~O");
			g->addVertex(L"Kolkata Airport~O");
			g->addVertex(L"Science city~BP");
			g->addVertex(L"EM Bypass~PR");
			g->addVertex(L"New market~P");

			g->addEdge(L"Sector 5~B", L"Botanical Garden~B", 8);
			g->addEdge(L"Botanical Garden~B", L"Ganga Bank~B", 10);
			g->addEdge(L"Ganga Bank~B", L"Alipore~B", 8);
			g->addEdge(L"Ganga Bank~B", L"Park street~BY", 6);
			g->addEdge(L"Park street~BY", L"Bhawanipore~B", 9);
			g->addEdge(L"Bhawanipore~B", L"Maidan~BO", 7);
			g->addEdge(L"Maidan~BO", L"Esplanade~B", 6);
			g->addEdge(L"City Center~Y", L"Salt lake~Y", 15);
			g->addEdge(L"Salt lake~Y", L"CMC~Y", 6);
			g->addEdge(L"CMC~Y", L"Park street~BY", 7);
			g->addEdge(L"Park street~BY", L"Kolkata~YO", 1);
			g->addEdge(L"Kolkata~YO", L"Chandni Chowk~Y", 2);
			g->addEdge(L"Chandni Chowk~Y", L"Victoria~Y", 5);
			g->addEdge(L"Kolkata~YO", L"Eden gardens Stadium~O", 2);
			g->addEdge(L"Eden gardens Stadium~O", L"Bidhannagar~O", 7);
			g->addEdge(L"DDS Campus~O", L"Kolkata Airport~O", 8);
			g->addEdge(L"Moti Nagar~B", L"Rajouri Garden~BP", 2);
			g->addEdge(L"Punjabi Bagh West~P", L"Rajouri Garden~BP", 2);
			g->addEdge(L"Punjabi Bagh West~P", L"Netaji Subhash Place~PR", 3);
}

std::vector<std::wstring> <missing_class_definition>::printCodelist()
{
	std::wcout << L"List of station along with their codes:\n" << std::endl;
	std::vector<std::wstring> keys(vtces::keySet());
	int i = 1, j = 0, m = 1;
	std::shared_ptr<StringTokenizer> stname;
	std::wstring temp = L"";
	std::vector<std::wstring> codes(keys.size());
	wchar_t c;
	for (auto key : keys)
	{
		stname = std::make_shared<StringTokenizer>(key);
		codes[i - 1] = L"";
		j = 0;
		while (stname->hasMoreTokens())
		{
				temp = stname->nextToken();
				c = temp[0];
				while (c > 47 && c < 58)
				{
						codes[i - 1] += c;
						j++;
						c = temp[j];
				}
				if ((c < 48 || c>57) && c < 123)
				{
						codes[i - 1] += c;
				}
		}
		if (codes[i - 1].length() < 2)
		{
			codes[i - 1] += std::toupper(temp[1]);
		}

		std::wcout << i << L". " << key << L"\t";
		if (key.length() < (22 - m))
		{
						std::wcout << L"\t";
		}
		if (key.length() < (14 - m))
		{
						std::wcout << L"\t";
		}
					if (key.length() < (6 - m))
					{
						std::wcout << L"\t";
					}
					std::wcout << codes[i - 1] << std::endl;
		i++;
		if (i == static_cast<int>(std::pow(10,m)))
		{
				m++;
		}
	}
	return codes;
}
public:
static void main(std::vector<std::wstring> &args);



#include <string>
#include <vector>

int main(int argc, char **argv)
{
	std::vector<std::wstring> args(argv + 1, argv + argc);
	main(args);
}





void <missing_class_definition>::main(std::vector<std::wstring> &args)
		{
			std::shared_ptr<Graph_M> g = std::make_shared<Graph_M>();
			Create_Metro_Map(g);

			std::wcout << L"\n\t\t\t****WELCOME TO THE METRO APP*****" << std::endl;
std::shared_ptr<BufferedReader> inp = std::make_shared<BufferedReader>(std::make_shared<InputStreamReader>(System::in));
while (true)
			{
				std::wcout << L"\t\t\t\t~~LIST OF ACTIONS~~\n\n" << std::endl;
				std::wcout << L"1. LIST ALL THE STATIONS IN THE MAP" << std::endl;
				std::wcout << L"2. SHOW THE METRO MAP" << std::endl;
				std::wcout << L"3. GET SHORTEST DISTANCE FROM A 'SOURCE' STATION TO 'DESTINATION' STATION" << std::endl;
				std::wcout << L"4. GET SHORTEST TIME TO REACH FROM A 'SOURCE' STATION TO 'DESTINATION' STATION" << std::endl;
				std::wcout << L"5. GET SHORTEST PATH (DISTANCE WISE) TO REACH FROM A 'SOURCE' STATION TO 'DESTINATION' STATION" << std::endl;
				std::wcout << L"6. GET SHORTEST PATH (TIME WISE) TO REACH FROM A 'SOURCE' STATION TO 'DESTINATION' STATION" << std::endl;
				std::wcout << L"7. EXIT THE MENU" << std::endl;
				std::wcout << L"\nENTER YOUR CHOICE FROM THE ABOVE LIST (1 to 7) : ";
				int choice = -1;
				try
				{
					choice = static_cast<int>(inp->readLine());
				}
				catch (const std::runtime_error &e)
				{
					// default will handle
				}
				std::wcout << L"\n***********************************************************\n";
				if (choice == 7)
				{
					exit(0);
				}
				switch (choice)
				{
				case 1:
					g->display_Stations();
					break;

				case 2:
					g->display_Map();
					break;

				case 3:
					std::vector<std::wstring> keys(vtces::keySet());
					std::vector<std::wstring> codes = printCodelist();
					std::wcout << L"\n1. TO ENTER SERIAL NO. OF STATIONS\n2. TO ENTER CODE OF STATIONS\n3. TO ENTER NAME OF STATIONS\n" << std::endl;
					std::wcout << L"ENTER YOUR CHOICE:" << std::endl;
						int ch = static_cast<int>(inp->readLine());
					int j;

					std::wstring st1 = L"", st2 = L"";
					std::wcout << L"ENTER THE SOURCE AND DESTINATION STATIONS" << std::endl;
					if (ch == 1)
					{
						st1 = keys[static_cast<int>(inp->readLine()) - 1];
						st2 = keys[static_cast<int>(inp->readLine()) - 1];
					}
					else if (ch == 2)
					{
						std::wstring a, b;
						a = (inp->readLine())->toUpperCase();
						for (j = 0;j < keys.size();j++)
						{
						   if (a == codes[j])
						   {
							   break;
						   }
						}
						st1 = keys[j];
						b = (inp->readLine())->toUpperCase();
						for (j = 0;j < keys.size();j++)
						{
						   if (b == codes[j])
						   {
							   break;
						   }
						}
						st2 = keys[j];
					}
					else if (ch == 3)
					{
						st1 = inp->readLine();
						st2 = inp->readLine();
					}
					else
					{
						std::wcout << L"Invalid choice" << std::endl;
						exit(0);
					}

					std::unordered_map<std::wstring, bool> processed;
					if (!g->containsVertex(st1) || !g->containsVertex(st2) || !g->hasPath(st1, st2, processed))
					{
						std::wcout << L"THE INPUTS ARE INVALID" << std::endl;
					}
					else
					{
					std::wcout << L"SHORTEST DISTANCE FROM " << st1 << L" TO " << st2 << L" IS " << g->dijkstra(st1, st2, false) << L"KM\n" << std::endl;
					}
					break;
case 4:
{
					std::wcout << L"ENTER THE SOURCE STATION: ";
					std::wstring sat1 = inp::readLine();
					std::wcout << L"ENTER THE DESTINATION STATION: ";
					std::wstring sat2 = inp::readLine();

					std::unordered_map<std::wstring, bool> processed1;
					std::wcout << L"SHORTEST TIME FROM (" << sat1 << L") TO (" << sat2 << L") IS " << g::dijkstra(sat1, sat2, true) / 60 << L" MINUTES\n\n" << std::endl;
					break;

}
				case 5:
				{
					std::wcout << L"ENTER THE SOURCE AND DESTINATION STATIONS" << std::endl;
					std::wstring s1 = inp::readLine();
					std::wstring s2 = inp::readLine();

					std::unordered_map<std::wstring, bool> processed2;
					if (!g::containsVertex(s1) || !g::containsVertex(s2) || !g::hasPath(s1, s2, processed2))
					{
						std::wcout << L"THE INPUTS ARE INVALID" << std::endl;
					}
					else
					{
						std::vector<std::wstring> str = g::get_Interchanges(g::Get_Minimum_Distance(s1, s2));
						int len = str.size();
						std::wcout << L"SOURCE STATION : " << s1 << std::endl;
						std::wcout << L"SOURCE STATION : " << s2 << std::endl;
						std::wcout << L"DISTANCE : " << str[len - 1] << std::endl;
						std::wcout << L"NUMBER OF INTERCHANGES : " << str[len - 2] << std::endl;
						//System.out.println(str);
						std::wcout << L"~~~~~~~~~~~~~" << std::endl;
						std::wcout << L"START  ==>  " << str[0] << std::endl;
						for (int i = 1; i < len - 3; i++)
						{
							std::wcout << str[i] << std::endl;
						}
						std::wcout << str[len - 3] << L"   ==>    END";
						std::wcout << L"\n~~~~~~~~~~~~~" << std::endl;
					}
					break;

				}
				case 6:
				{
					std::wcout << L"ENTER THE SOURCE STATION: ";
					std::wstring ss1 = inp::readLine();
					std::wcout << L"ENTER THE DESTINATION STATION: ";
					std::wstring ss2 = inp::readLine();

					std::unordered_map<std::wstring, bool> processed3;
					if (!g::containsVertex(ss1) || !g::containsVertex(ss2) || !g::hasPath(ss1, ss2, processed3))
					{
						std::wcout << L"THE INPUTS ARE INVALID" << std::endl;
					}
					else
					{
						std::vector<std::wstring> str = g::get_Interchanges(g::Get_Minimum_Time(ss1, ss2));
						int len = str.size();
						std::wcout << L"SOURCE STATION : " << ss1 << std::endl;
						std::wcout << L"DESTINATION STATION : " << ss2 << std::endl;
						std::wcout << L"TIME : " << str[len - 1] << L" MINUTES" << std::endl;
						std::wcout << L"NUMBER OF INTERCHANGES : " << str[len - 2] << std::endl;
						//System.out.println(str);
						std::wcout << L"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
						std::wcout << L"START  ==>  " << str[0] << L" ==>  ";
						for (int i = 1; i < len - 3; i++)
						{
							std::wcout << str[i] << std::endl;
						}
						std::wcout << str[len - 3] << L"   ==>    END";
						std::wcout << L"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
					}
					break;
				}
							default: //If switch expression does not match with any case,
								//default statements are executed by the program.
								//No break is needed in the default case
								std::wcout << L"Please enter a valid option! " << std::endl;
								std::wcout << L"The options you can choose are from 1 to 6. " << std::endl;

				}
			}

		}
	}
