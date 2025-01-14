/* Copyright (c) 2009-2013, Michele Dallachiesa, Carlo Nicolini
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY <copyright holder> ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <copyright holder> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _CNF_H
#define  _CNF_H

#include <set>
#include <map>
#include <vector>
#include <fstream>
#include "Graph.h"

typedef vector<long> Clause;
typedef vector<Clause> Clauses;

typedef set<long> Vars;
typedef set<long> Literals;
typedef map<long, Literals> ClausesLiterals;

#define GRAPHTYPE_VARIABLE_INTERACTION 0
#define GRAPHTYPE_RESOLUTION 1
#define GRAPHTYPE_MIN GRAPHTYPE_VARIABLE_INTERACTION
#define GRAPHTYPE_MAX GRAPHTYPE_RESOLUTION

/**
 * @brief The Cnf class This class loads a cnf file, follow
 * http://people.sc.fsu.edu/~jburkardt/data/cnf/cnf.html
 * http://minorityblog.wordpress.com/2006/07/03/parsing-cnf-with-scheme/
 */
class Cnf
{
public:
   Cnf();
   void loadFromFile(istream& is);
   void loadFromFile2(ifstream &file);
   Cnf(const Cnf& orig);
   virtual ~Cnf();
   bool buildVariableInteractionGraph(Graph *graph);
   bool buildResolutionGraph(Graph *graph);
   Clauses clauses;
   int nvars;

private:
   void print(ostream &os);

};

#endif   /* _CNF_H */

