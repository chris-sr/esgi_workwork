#include "chain.h"

#include "factory.h"
#include "types.h"
#include "worker.h"

ww::Chain::Chain(){
    _factory = NULL;
    _affected_workers = new std::vector<Worker*>();
}

ww::Chain::~Chain(){ 
    //Free the workers from this chain's tyranny
    for(uint i=0; i<_affected_workers->size(); i++){
        this->reject_worker(_affected_workers->at(i));
    }

    //Deallocate the stl container
    delete _affected_workers;

    //Notify the factory we are destroying a chain
    if(NULL != _factory){
        _factory->unregister_chain(this);
    }
    //Factory::get_reference().unregister_chain(this);
}

void
ww::Chain::affect_worker(Worker* worker){
    wwassert(NULL != worker);

    //Is that worker affected to a chain? (including this chain)
    if(NULL != worker->_affected_chain){
        //Remove that worker from it's affected chain
        worker->_affected_chain->reject_worker(worker);
    }

    //Affect this worker to me
    _affected_workers->push_back(worker);
    worker->_affected_chain = this;
    wwlog("affected worker " << worker
          << " to chain " << this << "\n");
}

void
ww::Chain::reject_worker(Worker* worker){
    wwassert(NULL != worker);
    for(uint i=0; i<_affected_workers->size(); i++){
        if(_affected_workers->at(i) == worker){
            _affected_workers->erase(_affected_workers->begin()+i);
            worker->_affected_chain = NULL;
            wwlog("removed worker " << worker
                  << " from chain " << this << "\n");
            return;
        }
    }

    wwlog("warning: worker " << worker << " is not affected "
          << "to chain " << this << "\n");
}
