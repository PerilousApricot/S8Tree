/**
 * Event 
 * s8 
 *
 * Created by Samvel Khalatian on Sep 28, 2010
 * Copyright 2010, All rights reserved
 */

#ifndef S8_EVENT
#define S8_EVENT

namespace s8
{
    /*
    class EventID;
    class GenEvent;
    class Jet;
    class Lepton;
    class PrimaryVertex;
    class Trigger;
    */

    class Event
    {
        /*
        public:
            typedef std::vector<Jet *>           Jets;
            typedef std::vector<Lepton *>        Leptons;
            typedef std::vector<PrimaryVertex *> PrimaryVertices;
            typedef std::vector<Trigger *>       Triggers;

            Event() throw();
            ~Event() throw();

            Event(const Event &);
            Event &operator =(const Event &);

            void reset();

            void manageMemory(const bool &);

            EventID *id();
            const EventID *id() const;

            GenEvent *gen();
            const GenEvent *gen() const;



            // Collections
            //
            Jets &jets();
            const Jets &jets() const;

            Leptons &muons();
            const Leptons &muons() const;

            Leptons &electrons();
            const Leptons &electrons() const;

            PrimaryVertices &primaryVertices();
            const PrimaryVertices &primaryVertices() const;

            Triggers &triggers();
            const Triggers &triggers() const;

        private:
            void cleanUpMemory();
            void cloneCollections(const Event &);

            bool _cleanUpMemory;

            EventID  *_id;
            GenEvent *_gen;

            Jets            _jets;
            Leptons         _muons;
            Leptons         _electrons;
            PrimaryVertices _primaryVertices;
            Triggers        _triggers;
            */
    };
}

#endif
